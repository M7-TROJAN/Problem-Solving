#include <iostream>
#include <fstream>
#include <string>

void PrintFileContent(const std::string& filePath)
{
    std::ifstream file(filePath);
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            std::cout << line << std::endl;
        }
        file.close();
    }
    else
    {
        std::cerr << "Error opening file: " << filePath << std::endl;
    }
}

int main()
{
    std::string fileName = "MyFile.txt";
    PrintFileContent(fileName);
    return 0;
}

/*
Improvements in the code include:

1- Using std::ifstream instead of std::fstream in read-only mode (ios::in) for reading the file.

2- Passing the filePath parameter as a constant reference (const std::string&) to avoid unnecessary copying.

3- Using std::cerr to output an error message if the file fails to open.

4- Declaring the fileName variable separately in the main function before calling PrintFileContent.

These improvements enhance code readability, utilize appropriate error handling, and follow best practices for file input/output operations in C++.
*/