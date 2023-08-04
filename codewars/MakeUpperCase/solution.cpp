#include <string>

std::string makeUpperCase (const std::string& input_str)
{
    std::string UpperCaseStr;
    for (char c : input_str)
    {
        UpperCaseStr += toupper(c);
    }
    return UpperCaseStr;
}