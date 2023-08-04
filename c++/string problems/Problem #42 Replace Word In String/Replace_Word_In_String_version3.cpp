#include <iostream>
#include <string>

// This function replaces all occurrences of a substring with another substring in a given string
std::string replaceSubstring(const std::string& originalStr, const std::string& oldSubstr, const std::string& newSubstr)
{
    std::string modifiedStr = originalStr;

    size_t currentPosition = 0;

    // Find and replace all occurrences of the old substring with the new substring
    while ((currentPosition = modifiedStr.find(oldSubstr, currentPosition)) != std::string::npos)
    {
        // Replace the old substring with the new substring
        modifiedStr.replace(currentPosition, oldSubstr.length(), newSubstr);

        // Update the current position to skip the newly inserted substring
        currentPosition += newSubstr.length();
    }

    return modifiedStr;
}

int main()
{
    std::string sentence = "Hi my name is Mahmoud, I love Egypt. Egypt is a beautiful country. Come to Egypt!";

    std::cout << "Your Original sentence Is:\n" << sentence << std::endl;
    std::cout << "Your modified sentence is:\n";
    std::cout << replaceSubstring(sentence, "Egypt", "Mecca") << std::endl;
    return 0;
}

/*
!replaceSubstring() function Explanation:

1- The function replaceSubstring takes three parameters: 'originalStr', which is the original string in which replacements will be made,
'oldSubstr', which is the substring to be replaced, and 'newSubstr', which is the substring to replace the occurrences of 'oldSubstr'.

2- A new string variable 'modifiedStr' is created and initialized with the value of 'originalStr'.
This allows us to make modifications to a separate string without modifying the original string directly.

3- A size_t variable 'currentPosition' is initialized to 0.
This variable will keep track of the current position in the 'modifiedStr' where the search for 'oldSubstr' will start.

4- The 'while' loop is executed as long as there are occurrences of 'oldSubstr' in 'modifiedStr'.
The condition '(currentPosition = modifiedStr.find(oldSubstr, currentPosition)) != std::string::npos' 
finds the next occurrence of 'oldSubstr' starting from the 'currentPosition'.
If no occurrence is found, 'std::string::npos' is returned, and the loop will exit.

5- Inside the loop, the 'replace' function is used to replace the 'oldSubstr' with 'newSubstr' in 'modifiedStr'.
The 'replace' function takes three parameters: the starting position '(currentPosition)',
the length of the substring to be replaced '(oldSubstr.length())' , and the new substring '(newSubstr)'.

6- After the replacement is made, 'currentPosition' is incremented by the length of 'newSubstr'.
This ensures that the next iteration of the loop starts searching for the next occurrence of 'oldSubstr'
after the recently inserted 'newSubstr'.

7- Once there are no more occurrences of 'oldSubstr' in 'modifiedStr',
the loop exits, and the final modified string 'modifiedStr' is returned.

*/

/*
!In summary:
the replaceSubstring function iterates over the original string, finds each occurrence of the specified substring to be replaced,
replaces it with the new substring, and returns the modified string.
This allows you to easily perform multiple replacements in a given string.
*/