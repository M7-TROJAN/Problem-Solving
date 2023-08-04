#include <iostream>
#include <string>

char get_char(const std::string& message = "")
{
    char letter = ' ';
    std::cout << message;
    std::cin >> letter;
    return letter;
}

std::string get_string(const std::string& message = "")
{
    std::string str;
    std::cout << message;
    std::getline(std::cin >> std::ws, str);
    return str;
}

// Function to Check if the Given Character Is a Vowel or Not
bool isVowel(char ch)
{
    ch = tolower(ch);
    switch (ch)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
    }
}

int main()
{
    char letter = get_char("Enter a letter to Check if it's a vowel: ");

    if (isVowel(letter))
        std::cout << "'" <<letter << "' is a vowel letter.\n";
    else
        std::cout << "'" <<letter << "' is not a vowel letter.\n";

    return 0;
}
