#include <iostream>
#include <string>

std::string reverse_words(const std::string& str)
{
    std::string result = ""; // Initialize an empty string to store the reversed words
    std::string temp = ""; // Initialize an empty string to store each word temporarily

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

int main()
{
    std::string input;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, input);

    std::string reversed = reverse_words(input);
    std::cout << "Reversed words: " << reversed << std::endl;

    return 0;
}
