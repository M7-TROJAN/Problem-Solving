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
std::vector<std::string> splitString(const std::string &str, const std::string &delimiter = " ")
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

// This function reverses the order of words in a string
std::string reverseStringWords(const std::string& str)
{
    std::vector<std::string> words = splitString(str);

    std::string reversedString;
    for (auto it = words.rbegin(); it != words.rend(); ++it)
    {
        reversedString += *it;
        if (std::next(it) != words.rend())
        {
            reversedString += " ";
        }
    }

    return reversedString;
}

int main()
{
    std::string sentence = getString("Enter a sentence: ");
    std::cout << "Your sentence words in reverse order are:\n";
    std::cout << reverseStringWords(sentence) << std::endl;
    return 0;
}
