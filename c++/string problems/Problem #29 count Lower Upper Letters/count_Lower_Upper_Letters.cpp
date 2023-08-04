#include <iostream>
#include <string>
using namespace std;

// Function to get a string input from the user
string get_string(const string &message = "")
{
    string str;
    cout << message;
    getline(cin, str);
    return str;
}

// Function to count the number of lowercase letters in a string
int countLowerLetters(const string &sentence)
{
    int lowerLettersCount = 0;
    for (const char &ch : sentence)
    {
        if (islower(ch))
            lowerLettersCount++;
    }
    return lowerLettersCount;
}

// Function to count the number of uppercase letters in a string
int countUpperLetters(const string &sentence)
{
    int upperLettersCount = 0;
    for (const char &ch : sentence)
    {
        if (isupper(ch))
            upperLettersCount++;
    }
    return upperLettersCount;
}

int main()
{
    string sentence;
    sentence = get_string("Enter a sentence: ");

    cout << "Number of uppercase letters: " << countUpperLetters(sentence) << endl;
    cout << "Number of lowercase letters: " << countLowerLetters(sentence) << endl;

    return 0;
}
