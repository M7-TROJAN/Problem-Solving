#include <iostream>
#include <string>

std::string getString(const std::string &message = "")
{
    std::string str;
    std::cout << message;
    std::getline(std::cin, str);
    return str;
}

// Trim the leading spaces from the string
std::string trimLeft(const std::string& str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
        {
            return str.substr(i); // returns from index 'i' until the end of the string.  =>  str.substr(i, str.length() - 1)
        }
    }
    return "";
}

// Trim the trailing spaces from the string
std::string trimRight(const std::string& str)
{
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] != ' ')
            return str.substr(0, i + 1);
    }
    return "";
}

// Trim the leading and trailing spaces from the string
std::string trim(const std::string& str)
{
    return trimLeft(trimRight(str));
}

int main()
{
    std::string sentence = getString("Enter a sentence: ");

    std::cout << "\nTrim Left: " << trimLeft(sentence) << std::endl;
    std::cout << "Trim Right: " << trimRight(sentence) << std::endl;
    std::cout << "Trim: " << trim(sentence) << std::endl;

    return 0;
}
