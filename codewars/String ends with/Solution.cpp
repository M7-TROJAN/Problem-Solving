#include <string>
bool solution(std::string const &str, std::string const &ending)
{
    if (ending == "")
        return true;
    int endingLength = ending.size();
    int strLength = str.size();
    for (int i = 0; i < ending.size(); i++)
    {
        if (ending[endingLength - 1 - i] != str[strLength - 1 - i])
            return false;
    }
    return true;
}