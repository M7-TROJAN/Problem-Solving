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

// This function calculates the sum of digits of a given number
int SumOfDigits(int Number)
{
    int Sum = 0, Remainder = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        Sum = Sum + Remainder;
    }
    return Sum;
}

int main()
{
    int result =0;
    
    result = SumOfDigits(ReadPositiveNumber("Please enter a positive number?"));

    cout << "===============================\n";
    cout << "Sum Of Digits = " << result << endl;

    return 0;
}