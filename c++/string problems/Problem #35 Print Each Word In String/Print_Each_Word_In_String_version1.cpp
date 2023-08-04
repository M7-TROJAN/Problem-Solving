#include <iostream>
#include <string>

std::string getString(const std::string& message = "")
{
    std::string str;
    std::cout << message;
    std::getline(std::cin, str);
    return str;
}
// This function prints each word in a given string
void printEachWordInString(std::string sentence)
{
    const std::string delimiter = " ";
    std::string currentWord;

    // Iterate through the sentence to extract and print each word
    size_t delimiterPos = 0;
    while ((delimiterPos = sentence.find(delimiter)) != std::string::npos)
    {
        currentWord = sentence.substr(0, delimiterPos);
        if (!currentWord.empty())
        {
            std::cout << currentWord << std::endl;
        }
        sentence.erase(0, delimiterPos + delimiter.length());
    }

    // Print the last word if it exists
    if (!sentence.empty())
    {
        std::cout << sentence << std::endl;
    }
}

int main()
{
    std::string sentence = getString("Enter a sentence: ");
    std::cout << "Your sentence words are:\n";
    printEachWordInString(sentence);
    return 0;
}

/*
1- The 'printEachWordInString' It takes a string 'sentence' as input and is responsible for printing each word in the sentence.

2- The 'delimiter' variable is defined as a constant string with a value of a space character.
This represents the delimiter that separates words in the sentence.

3- The 'currentWord' variable is declared to store each word extracted from the sentence.

4- The function enters a loop to iterate through the sentence and extract each word.

5- Inside the loop, the 'find' function is used to locate the position of the next occurrence of the delimiter in the sentence.
If no delimiter is found '(std::string::npos)', the loop terminates.

6- The 'substr' function is used to extract the word from the beginning of the sentence up to the position of the delimiter.
The extracted word is stored in the 'currentWord' variable.

7- If the extracted word is not empty, it is printed to the console.

8- The 'erase' function is used to remove the extracted word and the delimiter from the sentence,
so the next iteration of the loop can find the next word.
The position and length of the word and delimiter are calculated to specify the portion of the string to erase.

9- After the loop, there may be a remaining word in the 'sentence' variable. If it is not empty, it is printed as the last word.
*/