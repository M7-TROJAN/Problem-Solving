#include <iostream>
#include <string>
using namespace std;
string ReplaceWordInString(string originalStr, string StringToReplace, string stringReplaceTo)
{
    short pos = originalStr.find(StringToReplace);
    while (pos != std::string::npos)
    {
        originalStr = originalStr.replace(pos, StringToReplace.length(), stringReplaceTo);
        pos = originalStr.find(StringToReplace); // find next
    }
    return originalStr;
}

int main()
{
    string sentence = "Hi my name is Mahmoud, I love Egypt. Egypt is a beautiful country. Come to Egypt!";
    string StringToReplace = "Egypt";
    string ReplaceTo = "USA";
    cout << "\nOriginal String\n" << sentence;
    cout << "\n\nString After Replace:";
    cout << "\n" << ReplaceWordInString(sentence, StringToReplace, ReplaceTo);
}