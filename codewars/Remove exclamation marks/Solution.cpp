#include <string>
std::string removeExclamationMarks(std::string str)
{
    std::string s = "";
    for (char c : str)
    {
        if (c == '!')
            continue;
        s += c;
    }
    return s;
}