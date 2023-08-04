/*
Write a function that accepts an integer (n) and a string (s) as parameters, and returns a string of s repeated exactly (n) times.
*/

#include <string>
std::string repeat_str(size_t repeat, const std::string &str)
{
    std::string newStr = "";
    for (int i = 1; i <= repeat; i++)
        newStr += str;
    return newStr;

    // another way
    while(repeat--)
        newStr += str;
    
}

