#include <iostream>
#include <string>

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

// Function to print vowel letters in a given string
void printVowelLetters(const std::string& sentence)
{
    std::cout << "\nThe Vowel Letters In Your sentence Are:\n";
    for (const char &ch : sentence)
    {
        if (isVowel(ch))
            std::cout << ch << "  ";
    }
    std::cout << std::endl;
}

int main()
{
    std::string sentence = get_string("Enter a sentence: ");
    printVowelLetters(sentence);
    return 0;
}
