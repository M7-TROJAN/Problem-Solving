#include <iostream>
#include <string>

std::string getString(const std::string& message = "")
{
    std::string str;
    std::cout << message;
    std::getline(std::cin, str);
    return str;
}

// This function counts the number of words in a given string
size_t countWordsInString(std::string sentence)
{
    const std::string delimiter = " ";
    std::string currentWord;
    size_t wordCount = 0;

    // Iterate through the sentence to extract and count each word
    size_t delimiterPos = 0;
    while ((delimiterPos = sentence.find(delimiter)) != std::string::npos)
    {
        currentWord = sentence.substr(0, delimiterPos);
        if (!currentWord.empty())
        {
            wordCount++;
        }
        sentence.erase(0, delimiterPos + delimiter.length());
    }

    // Count the last word if it exists
    if (!sentence.empty())
    {
        wordCount++;
    }

    return wordCount;
}

int main()
{
    std::string sentence = getString("Enter a sentence: ");
    int wordCount = countWordsInString(sentence);
    std::cout << "The sentence contains " << wordCount << " words.\n";
    return 0;
}
