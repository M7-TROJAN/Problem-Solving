#include <iostream>
#include <string>

std::string getString(const std::string& message = "")
{
    std::string str;
    std::cout << message;
    std::getline(std::cin, str);
    return str;
}

// This function replaces all occurrences of a substring with another substring in a given string
std::string replaceSubstring(const std::string& originalStr, const std::string& oldSubstr, const std::string& newSubstr)
{
    std::string modifiedStr = originalStr;

    size_t currentPosition = 0;

    // Find and replace all occurrences of the old substring with the new substring
    while ((currentPosition = modifiedStr.find(oldSubstr, currentPosition)) != std::string::npos)
    {
        // Erase the old substring
        modifiedStr.erase(currentPosition, oldSubstr.length());

        // Insert the new substring at the same position
        modifiedStr.insert(currentPosition, newSubstr);

        // Update the current position to skip the newly inserted substring
        currentPosition += newSubstr.length();
    }

    return modifiedStr;
}

int main()
{
    std::string sentence = getString("Enter a sentence: ");
    std::string oldSubstring = getString("Enter the substring to replace: ");
    std::string newSubstring = getString("Enter the new substring: ");

    std::cout << "Your modified sentence is:\n";
    std::cout << replaceSubstring(sentence, oldSubstring, newSubstring) << std::endl;

    return 0;
}

/*
replaceSubstring() function Explanation:

1- The function takes three parameters: the original string '(originalStr)', the old substring to replace '(oldSubstr)',
and the new substring to insert '(newSubstr)'.

2- It creates a copy of the original string called 'modifiedStr', which will be modified to replace the old substring.

3- It initializes a variable 'currentPosition' to keep track of the current position while searching for occurrences of the old substring.
It starts at the beginning of the string '(currentPosition = 0)'.

4- The 'while' loop continues as long as there are more occurrences of the old substring in the string.
It uses the 'find' function to search for the next occurrence of the old substring starting from the current position.
If it finds an occurrence, it assigns the position to 'currentPosition', otherwise, it exits the loop.

5- Inside the loop, it performs the replacement steps:
    It erases the old substring from the modifiedStr using the erase function. The starting position is currentPosition,
    and the length is the length of the old substring (oldSubstr.length()).

    It inserts the new substring into the modifiedStr at the same position using the insert function.
    The starting position is currentPosition, and the new substring is newSubstr.

    It updates the currentPosition by adding the length of the new substring (newSubstr.length()).
    This is done to skip the newly inserted substring in the next iteration.

6- Once all occurrences of the old substring have been replaced, the function returns the modified string (modifiedStr).
*/