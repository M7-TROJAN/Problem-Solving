/*
    Read a positive integer from the user
    Reverse the number and display it
*/

#include <iostream>
using namespace std;

// This function reads a positive integer from the user and returns it
int ReadPositiveNumber(const string &message)
{
    int number = 0;
    do
    {
        // Display a message to the user asking for a positive integer
        cout << message << endl;

        // Read an integer value from the user
        cin >> number;

        // Check if the input was invalid (i.e. not an integer)
        if (cin.fail())
        {
            cin.clear();             // Clear the error flag
            cin.ignore(10000, '\n'); // Ignore any remaining characters in the input buffer
            cout << "Invalid input. Please enter a valid integer." << endl;
        }
        // Check if the input was negative or zero
        else if (number <= 0)
        {
            cout << "Invalid input. Please enter a positive integer." << endl;
        }
    } while (number <= 0);

    // Return the valid positive integer value entered by the user
    return number;
}

// This function takes a positive integer and returns its reverse
int ReverseNumber(int Number)
{
    int Remainder = 0, reversedNumber = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        reversedNumber = reversedNumber * 10 + Remainder;
    }
    return reversedNumber;
}

int main()
{   
    int ReversedNumber = 0;
    ReversedNumber = ReverseNumber(ReadPositiveNumber("Please enter a positive number?"));
    cout << "\nReverse is:\n" << ReversedNumber;
    
    return 0;
}