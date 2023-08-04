#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void LoadDataFromFileToVector(const std::string& FileName, std::vector<std::string>& vFileContent)
{
    std::ifstream MyFile(FileName); // ifstream is used for file input

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

int main()
{
    std::vector<std::string> vFileContent;
    LoadDataFromFileToVector("MyFile.txt", vFileContent);
    for (const std::string& Line : vFileContent)
    {
        std::cout << Line << std::endl;
    }

    return 0;
}
