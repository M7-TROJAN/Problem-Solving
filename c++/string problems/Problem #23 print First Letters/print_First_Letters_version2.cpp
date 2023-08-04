#include <iostream>
#include <string>
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
    bool newWord = true;
    for (const char &ch : sentence)
    {
        if (newWord && ch != ' ')
        {
            cout << ch << endl;
            newWord = false;
        }
        else if (ch == ' ')
            newWord = true;
    }
}

int main()
{
    string sentence;  // sentence => جملة
    sentence = get_string("Enter a sentence: ");

    cout << "First letters of each word:\n";
    printFirstLetters(sentence);

    return 0;
}
