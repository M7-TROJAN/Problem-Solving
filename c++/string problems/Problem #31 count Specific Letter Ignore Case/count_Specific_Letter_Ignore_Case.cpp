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

// Function to count the occurrences of a specific letter in a given string
int countSpecificLetter(const std::string& sentence, char target, bool MatchCase = true)
{
    int count = 0;
    for (const char &ch : sentence)
    {
        if (MatchCase)
        {
            if (ch == target)
                count++;
        }
        else
        {
            if (tolower(ch) == tolower(target))
                count++;
        }
    }
    return count;
}

int main()
{
    std::string sentence = get_string("Enter a sentence: ");
    char target = get_char("Enter a letter to count it: ");

    int letterCount = countSpecificLetter(sentence, target,false);
    std::cout << target << " occurs " << letterCount << " times (ignoring case) in the sentence.";

    return 0;
}
