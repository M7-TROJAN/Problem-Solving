#include <iostream>
#include <string>
#include <algorithm> // for all_of
using namespace std;

// Function to check if a string is all capital letters
bool isAllCaps(string s) {
    return all_of(s.begin(), s.end(), [](char c) { return isupper(c); });
}

// Function to read a 3-letter password from the user
string readPassword() {
    string password;
    cout << "Please enter a 3-Letter Password (all capital): ";
    cin >> password;
    while (password.length() != 3 || !isAllCaps(password)) {
        cout << "Invalid input. Please enter a 3-letter password in all capital letters: ";
        cin >> password;
    }
    return password;
}

// Function to guess the password by trying all possible combinations of 3 uppercase letters
bool guessPassword(string originalPassword) {
    string word;
    short counter = 0; // counter to keep track of number of guesses
    bool found = false; // flag to keep track of whether the correct password has been found
    for (short i = 65; i <= 90 && !found; i++) { // loop through all uppercase letters
        for (short j = 65; j <= 90 && !found; j++) {
            for (short k = 65; k <= 90 && !found; k++) {
                word = char(i);
                word += char(j);
                word += char(k);
                counter++;
                cout << "Trial [" << counter << "] : " << word << endl; // print the current guess
                if (word == originalPassword) { // check if the guess matches the original password
                    cout << "\nPassword is " << word << endl;
                    cout << "Found after " << counter << " trial(s)\n";
                    found = true;
                }
            }
        }
    }
    if (!found) { // handle case where password is not found within reasonable number of guesses
        cout << "Password not found within " << counter << " trials\n";
    }
    return found; // return true if password was found, false otherwise
}

int main() {
    guessPassword(readPassword()); // guess the password entered by the user
    return 0;
}
