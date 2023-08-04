#include <iostream>
#include <string>
#include <vector>

// Function to get input string from the user
std::string getString(const std::string& message = "")
{
    std::string str;
    std::cout << message;
    std::getline(std::cin, str);
    return str;
}

// Function to remove all punctuation letters from a given string
std::string removeAllPunctuationLetters(const std::string& originalStr)
{
    std::string modifiedStr = originalStr;

    /*
    Iterate over the string in reverse order
    By iterating over the string in reverse order,
    the characters will be safely removed without affecting the correctness of the results.
    */
    for (int i = modifiedStr.length() - 1; i >= 0; i--)
    {
        // Check if the character is a punctuation letter
        if (ispunct(modifiedStr[i]))
            modifiedStr.erase(i, 1); // Remove the punctuation letter
        
    }

    return modifiedStr;
}

int main()
{
    std::string sentence = getString("Enter your sentence: ");

    std::cout << "Your sentence after removing all punctuation letters:\n";
    std::cout << removeAllPunctuationLetters(sentence) << std::endl;

    return 0;
}
