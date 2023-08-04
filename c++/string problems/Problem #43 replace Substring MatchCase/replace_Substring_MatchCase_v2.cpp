#include <iostream>
#include <string>
#include <vector>

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

// This function joins a vector of strings into a single string using a delimiter
std::string joinString(const std::vector<std::string> &vString, const std::string &delimiter = " ")
{
    std::string result = "";
    for (int i = 0; i < vString.size(); i++)
    {
        result += vString.at(i);
        if (i != vString.size() - 1)
            result += delimiter;
    }
    return result;
}

// InvertStringLettersToLowercase is a function to invert the case of all letters in a string
std::string lowerAllStringLetters(const std::string &originalStr)
{
    // Create a copy of the input sentence
    std::string modifiedStr;

    // Iterate over each character in the sentence
    for (const char & c : originalStr)
    {
        modifiedStr += tolower(c);
    }
    // Return the modified sentence with  letter case
    return modifiedStr;
}

/* This function replaces occurrences of a substring in a given string, with optional case sensitivity.
It splits the original string into words, and for each word, checks if it matches the old substring.
If a match is found, the word is replaced with the new substring.
The modified words are then joined back into a single string and returned. */
std::string replaceSubstringMatchCase(const std::string& originalStr, const std::string& oldSubstr, const std::string& newSubstr, bool matchCase = true)
{
    // Split the original string into words
    std::vector<std::string> words = splitString(originalStr);
    
    // Iterate over each word
    for(std::string& word : words)
    {
        // Check if the case should be matched or ignored
        if(matchCase)
        {
            // If case should be matched, replace the word if it matches the old substring
            if(word == oldSubstr)
                word = newSubstr;
        }
        else
        {
            // If case should be ignored, replace the word if it matches the old substring (case-insensitive)
            if(lowerAllStringLetters(word) == lowerAllStringLetters(oldSubstr))
                word = newSubstr;
        }
    }
    
    return joinString(words);
}

int main()
{
    std::string sentence = "Welcome to Egypt Egypt is a nice country";
    std::string oldSubstring = "egypt";
    std::string newSubstring = "Mecca";

    std::cout << "Original sentence is:\n" << sentence << "\n";
    std::cout << "==============================\n";

    std::cout << "modified sentence with match case is:\n";
    std::cout << replaceSubstringMatchCase(sentence, oldSubstring, newSubstring) << std::endl;
    std::cout << "==============================\n";

    std::cout << "modified sentence without match case is:\n";
    std::cout << replaceSubstringMatchCase(sentence, oldSubstring, newSubstring, false) << std::endl;
    std::cout << "==============================\n";

    return 0;
}