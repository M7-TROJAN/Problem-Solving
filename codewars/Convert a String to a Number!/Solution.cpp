#include <string>
int string_to_number(const std::string &s)
{
    // your code here
    int number = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '-')
            continue;
        number = number * 10 + s[i] - '0';
    }
    if (s[0] == '-')
        number = -number;
    return number;
}