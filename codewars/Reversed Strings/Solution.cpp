#include <string>
using namespace std;

string reverseString(string str)
{
    // your Code is Here ... enjoy !!!
    int strlen = str.size();
    string reversed = str;
    for (int i = 0; i < strlen; i++)
    {
        reversed[i] = str[strlen - 1 - i];
    }
    return reversed;
}

// another solution

// string reverseString(string str)
// {
//     string reversed = "";
//     for (int i = str.size() - 1; i >= 0; i--)
//         reversed+= str[i];
//     return reversed;
// }