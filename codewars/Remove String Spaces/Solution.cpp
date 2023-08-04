/*
Write a function that removes the spaces from the string, then return the resultant string.

Examples:
Input    ->   Output
"8 j 8"        8j8
*/

#include <string>
#include <iostream>

std::string no_space(const std::string &str)
{
    std::string newStr;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
            continue;
        newStr += str[i];
    }
    return newStr;
}

int main()
{
    std:: cout << no_space("m a h m o u d");
}