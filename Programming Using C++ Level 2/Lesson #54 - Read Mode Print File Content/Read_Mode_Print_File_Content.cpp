#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void PrintFileContent(string FilePath)
{
    fstream MyFile;
    MyFile.open(FilePath, ios::in); // read Mode
    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
            cout << Line << endl;
        }
        MyFile.close();
    }
}

int main()
{
    PrintFileContent("MyFile.txt");
    return 0;
}
