#include <vector>
using namespace std;
std::vector<int> digitize(unsigned long n) 
{
    if(n == 0) return {0};

    vector<int> result;
    int Remainder = 0;

    while (n > 0)
    {
        Remainder = n % 10;
        result.push_back(Remainder);
        n /= 10;
    }
    return result;
}

// ............................................................

#include <vector>
std::vector<int> digitize(unsigned long n) 
{        
    std::vector<int> result;
    do {
        result.push_back(n % 10);
    }
    while (n /= 10);
    return result;
}

// ............................................................

#include <vector>
#include <string>
std::vector<int> digitize(unsigned long n) {
    std::vector<int> result;
    std::string str = std::to_string(n);
    std::reverse(str.begin(), str.end());

    for (int i = 0; i < str.length(); i++) 
        result.push_back(str[i]-'0');
    return result;
}

/*
    str = "795843";

    str[0] = '7'
    '7' in ASCII = 55
    '0' in ASCII = 48
    then '7' - '0' = 7  =>  55 - 48  = 7

    str[1] = '9'
    '9' in ASCII = 57
    '0' in ASCII = 48
    then '9' - '0' = 9  =>  57 - 48  = 9
*/
