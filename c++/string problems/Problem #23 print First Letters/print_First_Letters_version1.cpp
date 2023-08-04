#include <string>
#include <iostream>
using namespace std;

string get_string(const string &message = "")
{
    string str;
    cout << message;
    getline(cin, str);
    return str;
}
void printFirstLetters(const string& sentence)
{
    bool isFirstLetter = true;
    cout << "\nFirst letters of this string: \n";
    for (short i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] != ' ' && isFirstLetter)
        {
            cout << sentence[i] << endl;
        }
        isFirstLetter = (sentence[i] == ' ' ? true : false);
    }
}
int main()
{
    printFirstLetters(get_string("Enter a sentence: "));
}