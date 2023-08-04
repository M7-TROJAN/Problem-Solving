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

// Function to count the occurrences of vowel letters in a given string
int countVowelLetters(const std::string& sentence)
{
    int count = 0;
    for (const char &ch : sentence)
    {
        if (isVowel(ch))
            count++;
    }
    return count;
}

int main()
{
    std::string sentence = get_string("Enter a sentence: ");
    std::cout << "\nYour sentence Has " << countVowelLetters(sentence) << " Vowel Letter.\n";
    return 0;
}
