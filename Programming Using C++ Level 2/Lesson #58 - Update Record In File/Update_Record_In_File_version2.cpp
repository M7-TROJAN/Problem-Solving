/*
This improved code handles file opening errors and provides informative error messages.
It also uses pass-by reference to avoid unnecessary copying of vectors.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void LoadDataFromFileToVector(const string& FileName, vector<string>& vFileContent)
{
    ifstream MyFile(FileName);
    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
            vFileContent.push_back(Line);
        }
        MyFile.close();
    }
    else
    {
        cerr << "Error opening file: " << FileName << endl;
    }
}

void SaveVectorToFile(const string& FileName, const vector<string>& vFileContent)
{
    ofstream MyFile(FileName);
    if (MyFile.is_open())
    {
        for (const string& Line : vFileContent)
        {
            if (!Line.empty())
            {
                MyFile << Line << endl;
            }
        }
        MyFile.close();
    }
    else
    {
        cerr << "Error opening file: " << FileName << endl;
    }
}

void UpdateRecordInFile(const string& FileName, const string& Record, const string& UpdateTo)
{
    vector<string> vFileContent;
    LoadDataFromFileToVector(FileName, vFileContent);
    for (string& Line : vFileContent)
    {
        if (Line == Record)
        {
            Line = UpdateTo;
        }
    }
    SaveVectorToFile(FileName, vFileContent);
}

void PrintFileContent(const string& FileName)
{
    ifstream MyFile(FileName);
    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
            cout << Line << endl;
        }
        MyFile.close();
    }
    else
    {
        cerr << "Error opening file: " << FileName << endl;
    }
}

int main()
{
    cout << "File Content Before Update:\n";
    PrintFileContent("MyFile.txt");

    UpdateRecordInFile("MyFile.txt", "Ali", "Omar");

    cout << "\nFile Content After Update:\n";
    PrintFileContent("MyFile.txt");

    return 0;
}
