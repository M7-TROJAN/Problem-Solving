#include <string>
std::string number_to_string(int num)
{
    bool isNegative = num < 0;
    if (isNegative)
        num = -num;

    std::string result;
    if (num == 0)
    {
        result = "0";
    }
    else
    {
        while (num > 0)
        {
            int digit = num % 10;
            char digitChar = '0' + digit;
            result = digitChar + result;
            num /= 10;
        }
    }

    if (isNegative)
        result = '-' + result;

    return result;
}