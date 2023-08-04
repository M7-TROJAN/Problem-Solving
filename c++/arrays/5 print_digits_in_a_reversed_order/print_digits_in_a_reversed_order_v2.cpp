#include <iostream>
#include <string>
using namespace std;

// This function reads a positive integer from the user and returns it
int ReadPositiveNumber(const std::string& message)
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
            cin.clear(); // Clear the error flag
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

// This function prints the digits of a positive integer in reverse order
void PrintDigits(int Number)
{

    cout << "================\n";
    cout << "THe Reversed Is:\n";

    int Remainder = 0;
    while (Number > 0)
    {
        Remainder = Number % 10; // Get the rightmost digit
        Number = Number / 10; // Remove the rightmost digit
        cout << Remainder; // Print the rightmost digit
    }
    cout << endl;
/* 
in this function we used tow mathematical logic

The expression Number % 10 calculates the remainder of Number when divided by 10.
This gives the rightmost digit of Number.
For example, if Number is 123, then Number % 10 will be 3, which is the rightmost digit.

The expression Number / 10 divides Number by 10 and gives the result as an integer value.
This operation removes the rightmost digit of Number.
For example, if Number is 123, then Number / 10 will be 12, which is Number without the rightmost digit.
*/
}

int main()
{
    PrintDigits(ReadPositiveNumber("Please enter a positive number?"));
    return 0;
}