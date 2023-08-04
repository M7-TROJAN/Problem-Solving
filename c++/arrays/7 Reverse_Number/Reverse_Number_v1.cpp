#include <iostream>
using namespace std;

// This function reads a positive integer from the user and returns it
int ReadPositiveNumber(const std::string &message)
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

// This function takes an integer number as input and returns its reverse
int ReverseNumber(int Number)
{
    string StringNumber = "";
    int Remainder = 0;
    int ReversedNumber;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        StringNumber += to_string(Remainder);
    }
    ReversedNumber = atoi(StringNumber.c_str());
    return ReversedNumber;
}

int main()
{
    int ReversedNumber = 0;
    
    ReversedNumber = ReverseNumber(ReadPositiveNumber("Please enter a positive number?"));

    cout << "===============================\n";
    cout << "Reversed Number Is " << ReversedNumber << endl;

    return 0;
}