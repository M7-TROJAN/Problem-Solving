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
int countSpecificLetter(const std::string& sentence, char target)
{
    int count = 0;
    for (const char &ch : sentence)
    {
        if (ch == target)
            count++;
    }
    return count;
}

int main()
{
    std::string sentence = get_string("Enter a sentence: ");
    char target = get_char("Enter a letter to count it: ");

    int letterCount = countSpecificLetter(sentence, target);
    std::cout << target << " occurs " << letterCount << " times in the sentence.";

    return 0;
}
