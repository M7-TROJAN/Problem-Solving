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

// Function to Lowercased the first letter of each word in a string
std::string lowercaseFirstLetterOfEachWord(const std::string& sentence)
{
    std::string LowercasedSentence = sentence;
    bool newWord = true;
    for (char& ch : LowercasedSentence)
    {
        if (newWord && std::isalpha(ch))
            ch = std::tolower(ch);
        newWord = (ch == ' ' ? true : false);
    }
    return LowercasedSentence;
}

int main()
{
    string sentence;  // sentence => جملة
    sentence = get_string("Enter a sentence: ");

    cout << "Lowercased first letter of each word:\n";
    cout << lowercaseFirstLetterOfEachWord(sentence);

    return 0;
}