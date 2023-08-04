#include <string>

bool is_uppercase(const std::string &s)
{
    for (int i = 0; s[i] != 0; ++i)
        if (s[i] >= 97 && s[i] <= 122)
            return false;
    return true;
}
