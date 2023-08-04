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

int ReadNumber(string message)
{
    int number = 0;

    do
    {
        // Display a message to the user asking for a non negative integer
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
        // Check if the input was negative
        else if (number < 0)
        {
            cout << "Invalid input. Please enter a positive integer." << endl;
        }
    } while (number < 0);
    
    return number;

}

int CountDigitFrequency(int Number, short DigitToCheck)
{
/*  
    This function takes two arguments, an integer Number and a short integer DigitToCheck.
    It counts the frequency of DigitToCheck in Number by repeatedly 
*/
    int FreqCount = 0, Remainder = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        if (DigitToCheck == Remainder)
        {
            FreqCount++;
        }
    }
    return FreqCount;
}

int main()
{
    int Number = ReadPositiveNumber("Please enter the main number?"); 
    short DigitToCheck = ReadNumber("Please enter one digit to check?");

    int result = CountDigitFrequency(Number, DigitToCheck);

    cout << "===============================\n";
    cout << "Digit " << DigitToCheck << " Frequency is " << result << " Times." << endl;

    return 0;
}