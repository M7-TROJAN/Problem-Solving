#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void SaveVectorToFile(const std::string& FileName, const std::vector<std::string>& vFileContent)
{
    std::ofstream MyFile(FileName); // ofstream is used for file output

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

int main()
{
    std::vector<std::string> vFileContent{
        "Mahmoud", "Mohamed", "Abdalaziz", "Mousa", "Mesbah", "Mattar"};
    SaveVectorToFile("MyFile.txt", vFileContent);
    return 0;
}
