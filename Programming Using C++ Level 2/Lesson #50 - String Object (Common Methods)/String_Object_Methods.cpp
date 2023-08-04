#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str = "My Name is Mahmoud Mattar, I Love Programming.";

    // Prints the length of the string
    cout << str.length() << endl;

    // Returns the letter at position 3 => index[3]
    cout << str.at(3) << endl;

    // Adds @M7_TROJAN to the end of string
    str.append(" @M7_TROJAN");
    cout << str << endl;

    // inserts Ali at position 7 => index[7]
    str.insert(7, " Ali ");
    cout << str << endl;

    // Prints all the next 8 letters from position 16.
    cout << str.substr(16, 8) << endl;

    // Adds one character to the end of the string
    str.push_back('X');
    cout << str << endl;

    // Removes one character from the end of the string
    str.pop_back();
    cout << str << endl;

    // Finds Ali in the string
    cout << str.find("Ali") << endl;

    // Finds ali in the string
    cout << str.find("ali") << endl;
    /*
    The .find() method returns the position of the first occurrence of the given substring or character within the std::string.
    If the substring or character is found, it returns the index (position) of the first character of the found substring or character.
    If the substring or character is not found, it returns a special constant value std::string::npos,
    which typically has the value -1 or a very large value like 18446744073709551615.
    */

    if (str.find("ali") == str.npos)    // npos means => No Position it's equals 18446744073709551615 or -1
    {
        cout << "ali is not found";
    }

    // clears all string letters.
    str.clear();
    cout << str << endl;
    return 0;
}