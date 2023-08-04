#include <string>
#include <iostream>

std::string getString(const std::string& message = "")
{
    std::string str;
    std::cout << message;
    std::getline(std::cin, str);
    return str;
}

std::string toUpperCase(const std::string& str)
{
    std::string result = str;
    for (char& ch : result)
    {
        ch = std::toupper(ch);
    }
    return result;
}

std::string toLowerCase(const std::string& str)
{
    std::string result = str;
    for (char& ch : result)
    {
        ch = std::tolower(ch);
    }
    return result;
}

int main()
{
    std::string sentence = getString("Enter a sentence: ");

    std::cout << "\nSentence after converting to upper case:\n";
    std::string upperCaseSentence = toUpperCase(sentence);
    std::cout << upperCaseSentence << std::endl;
    std::cout << "========================================\n";

    std::cout << "Sentence after converting to lower case:\n";
    std::string lowerCaseSentence = toLowerCase(sentence);
    std::cout << lowerCaseSentence << std::endl;

    return 0;
}
