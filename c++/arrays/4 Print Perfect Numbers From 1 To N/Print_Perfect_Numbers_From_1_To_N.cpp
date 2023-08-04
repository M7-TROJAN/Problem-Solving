
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

// This function checks if a given number is a perfect number
bool isPerfectNumber(int Number)
{
    int Sum = 0;
    // Iterate over all factors of the number except the number itself
    for (int i = 1; i < Number; i++)
    {
        // If the current factor is a divisor of the number, add it to the sum
        if (Number % i == 0)
            Sum += i;
    }
    // Check if the sum of factors equals the number (i.e. the number is perfect)
    return Number == Sum;
}

// This function prints all the perfect numbers from 1 to a given number
void PrintPerfectNumbersFrom1ToN(int Number)
{
    cout << "\nAll Perfect Numbers From 1 To " << Number << " Are:\n";
    cout << "=====================================\n";
    // Iterate over all numbers from 1 to the given number
    for (int i = 1; i <= Number; i++)
    {
        // Check if the current number is a perfect number
        if (isPerfectNumber(i))
            cout << i << endl;
    }
    cout << "=====================================\n";
}

int main()
{
    // Read a positive integer from the user
    int number = ReadPositiveNumber("Please enter a positive integer:");

    // Print all the perfect numbers from 1 to the given number
    PrintPerfectNumbersFrom1ToN(number);

    return 0;
}
