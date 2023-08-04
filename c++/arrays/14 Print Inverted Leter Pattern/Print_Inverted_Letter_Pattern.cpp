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

void PrintInvertedLetterPattern(int Number)
{
    cout << "====================\n";
    for (int i = 65 + Number - 1; i >= 65; i--)
    {
        for (int j = 65; j <= i; j++)
        {
            cout << char(i);
        }
        cout << "\n";
    }
}

int main()
{
    PrintInvertedLetterPattern(ReadPositiveNumber("Please enter a positive number?"));
    return 0;
}