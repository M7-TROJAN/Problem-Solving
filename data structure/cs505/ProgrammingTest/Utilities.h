#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// This function splits a string into words using a delimiter
vector<string> splitString(const string& str, const string& delimiter)
{
    vector<string> words;
    string currentWord;

    // Iterate through the string to extract and add each word to the vector
    size_t delimiterPos = 0;
    string remainingStr = str; // Store the remaining string for manipulation
    while ((delimiterPos = remainingStr.find(delimiter)) != string::npos)
    {
        currentWord = remainingStr.substr(0, delimiterPos);
        if (!currentWord.empty())
        {
            words.push_back(currentWord);
        }
        remainingStr.erase(0, delimiterPos + delimiter.length());
    }

    // Add the last word if it exists
    if (!remainingStr.empty())
    {
        words.push_back(remainingStr);
    }

    return words;
}

// Trim the leading spaces from the string
string trimLeft(const string& str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
            return str.substr(i); // returns from index 'i' until the end of the string.  =>  str.substr(i, str.length() - 1)
    }
    return "";
}

// Trim the trailing spaces from the string
string trimRight(const string& str)
{
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] != ' ')
            return str.substr(0, i + 1);
    }
    return "";
}

// Trim the leading and trailing spaces from the string
string trim(const string& str)
{
    return trimLeft(trimRight(str));
}

void makeSeparator(int size)
{
    for (int i = 0; i < size; i++)
        cout << "-";
    cout << "\n";
}

// Reads an integer value from the user between the given range and returns it
int readNumber_From_To(int from, int to, string message = "")
{
    float number = 0;
    do
    {
        // Read an integer value from the user
        cout << message;
        cin >> number;

        // Check if the input was invalid (i.e. not an integer)
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a valid integer between " << from << " to " << to << endl;
            continue;
        }
        if (number < from || number > to)
        {
            cout << "Please enter a number between " << from << " to " << to << endl;
            continue;
        }
        break;
    } while (true);
    return number;
}