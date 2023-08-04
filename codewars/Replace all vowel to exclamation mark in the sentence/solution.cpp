#include <string>
using namespace std;

// Function to Check if the Given Character Is a Vowel or Not
bool isVowel(char ch)
{
    ch = tolower(ch);
    switch (ch)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    default:
        return false;
    }
}

string replace(const string &s)
{
    string newStr = s;
    for (char &c : newStr)
    {
        if (isVowel(c))
            c = '!';
    }
    return newStr;
}

// ..........................................................................

#include <string>
using namespace std;
string replace(string s)
{
    string vowels = "aeiouAEIOU";
    for (auto &c : s)
        if (vowels.find(c) != string::npos)
            c = '!';
    return move(s);
}

// ..........................................................................

#include <string>
#include <regex>
using namespace std;
string replace(string s)
{
    regex pattern ("[aeiouAEIOU]");

    return regex_replace(s, pattern, "!");

}