#include <string>
using namespace std;
std::string fakeBin(std::string str)
{
    for (char &c : str)
    {
        if (isdigit(c) && c < '5')
            c = '0';
        if (isdigit(c) && c >= '5')
            c = '1';
    }
    return str;
}

// ...........................................................................

#include <string>

std::string fakeBin(std::string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = ((str[i] - '0') > 4) ? '1' : '0';
    }
    return str;
}
