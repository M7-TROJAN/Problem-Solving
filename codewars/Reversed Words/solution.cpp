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

std::string reverse_words(const std::string &str)
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


// ......................................................................................................

// another solution without using splitString() function and without using vector.
#include <string>
using namespace std;

string reverse_words(const string& str)
{
    string result = ""; // Initialize an empty string to store the reversed words
    string temp = ""; // Initialize an empty string to store each word temporarily

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            // If a space is encountered, it means the current word is complete
            // Append the temporary word to the result string along with a space
            result = temp + " " + result;
            temp = ""; // Reset the temporary string for the next word
        }
        else
        {
            // If a non-space character is encountered, append it to the temporary string
            temp += str[i];
        }
    }

    // Add the last word to the result string (there is no space after the last word)
    result = temp + " " + result;

    return result;
}