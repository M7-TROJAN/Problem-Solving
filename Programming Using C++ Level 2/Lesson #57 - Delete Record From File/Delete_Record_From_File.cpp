#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Load data from file into a vector
void LoadDataFromFileToVector(const std::string& FileName, std::vector<std::string>& vFileContent)
{
    std::ifstream MyFile(FileName);

    if (MyFile.is_open())
    {
        std::string Line;
        while (std::getline(MyFile, Line))
        {
            vFileContent.push_back(Line);
        }
        MyFile.close();
    }
    else
    {
        std::cerr << "Error opening file: " << FileName << std::endl;
    }
}

// Save vector content to a file
void SaveVectorToFile(const std::string& FileName, const std::vector<std::string>& vFileContent)
{
    std::ofstream MyFile(FileName);

    if (MyFile.is_open())
    {
        for (const std::string& Line : vFileContent)
        {
            if (!Line.empty())
            {
                MyFile << Line << std::endl;
            }
        }
        MyFile.close();
    }
    else
    {
        std::cerr << "Error opening file: " << FileName << std::endl;
    }
}

// Delete a record from a file
void DeleteRecordFromFile(const std::string& FileName, const std::string& Record)
{
    std::vector<std::string> vFileContent;
    LoadDataFromFileToVector(FileName, vFileContent);

    for (std::string& Line : vFileContent)
    {
        if (Line == Record)
        {
            Line = "";
        }
    }
    SaveVectorToFile(FileName, vFileContent);
}

// Print the content of a file
void PrintFileContent(const std::string& FileName)
{
    std::ifstream MyFile(FileName);

    if (MyFile.is_open())
    {
        std::string Line;
        while (std::getline(MyFile, Line))
        {
            std::cout << Line << std::endl;
        }
        MyFile.close();
    }
    else
    {
        std::cerr << "Error opening file: " << FileName << std::endl;
    }
}

int main()
{
    // Print file content before deletion
    std::cout << "File Content Before Delete.\n";
    PrintFileContent("MyFile.txt");

    // Delete a record from the file
    DeleteRecordFromFile("MyFile.txt", "Ali");

    // Print file content after deletion
    std::cout << "\n\nFile Content After Delete.\n";
    PrintFileContent("MyFile.txt");

    return 0;
}





void DeleteRecordFromFile(const std::string& FileName, const std::string& Record)
{
    std::vector<std::string> vFileContent;
    LoadDataFromFileToVector(FileName, vFileContent);

    for (auto itr = vFileContent.begin(); itr != vFileContent.end();)
    {
        if (*itr == Record)
        {
            itr = vFileContent.erase(itr);  // Update iterator after erasing element
        }
        else
        {
            ++itr;
        }
    }
    SaveVectorToFile(FileName, vFileContent);
}
