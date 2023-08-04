#include <string>

bool isPalindrome(const std::string &str)
{
    const size_t len = str.length();
    for (size_t i = 0; i < len / 2; i += 1)
    {
        if (tolower(str[i]) != tolower(str[len - i - 1]))
        {
            return false;
        }
    }
    return true;
}