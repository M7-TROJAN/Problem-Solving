#include <iostream>
#include <string>
#include <sstream>

std::string get_string(const std::string& message = "")
{
    std::string str;
    std::cout << message;
    std::getline(std::cin, str);
    return str;
}

void PrintEachWordInString(const std::string& sentence)
{
    std::cout << "Your sentence words are:\n";

    std::istringstream iss(sentence);
    std::string word;
    while (iss >> word)
    {
        std::cout << word << "\n";
    }
}

int main()
{
    std::string sentence = get_string("Enter a sentence: ");
    PrintEachWordInString(sentence);
    return 0;
}
