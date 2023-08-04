#include <iostream>
std::string to_alternating_case(const std::string& str)
{
    std::string newStr = "";
    for (char c : str)
    {
        if(c >= 97 && c <= 122)
            newStr += (c - 32);
        else if(c >= 65 && c <= 90)
            newStr += (c + 32);
        else
            newStr += c;
    }
    
	return newStr;
}