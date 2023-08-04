#include <iostream>
#include <string>
#include <vector>

std::string getString(const std::string &message = "")
{
    std::string str;
    std::cout << message;
    std::getline(std::cin, str);
    return str;
}

// This function splits a string into words using a delimiter
std::vector<std::string> splitString(const std::string& str, const std::string& delimiter = " ")
{
    std::vector<std::string> words;
    std::string currentWord;

    // Iterate through the string to extract and add each word to the vector
    size_t delimiterPos = 0;
    std::string remainingStr = str; // Store the remaining string for manipulation
    while ((delimiterPos = remainingStr.find(delimiter)) != std::string::npos)
    {
        currentWord = remainingStr.substr(0, delimiterPos);
        if (!currentWord.empty())
        {
            words.push_back(currentWord);
        }
        remainingStr.erase(0, delimiterPos + delimiter.length());
    }

    // Add the last word if it exists
    if (!remainingStr.empty())
    {
        words.push_back(remainingStr);
    }

    return words;
}

int main()
{
    std::string sentence = getString("Enter a sentence: ");

    std::vector<std::string> words = splitString(sentence);

    std::cout << "Tokens" << words.size() << std::endl;
    for (const std::string& word : words)
    {
        std::cout << word << "\n";
    }
    return 0;
}
