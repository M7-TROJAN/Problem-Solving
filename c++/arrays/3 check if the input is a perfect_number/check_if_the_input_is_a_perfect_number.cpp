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
bool IsPerfectNumber(int number)
{
    int sum = 0;
    // Iterate over all factors of the number except the number itself
    for (int i = 1; i < number; i++)
    {
        // If the current factor is a divisor of the number, add it to the sum
        if (number % i == 0)
            sum += i;
    }
    // Check if the sum of factors equals the number (i.e. the number is perfect)
    return number == sum;
}

// This function prints the results of checking a number for being a perfect number
void PrintResults(int number)
{
    if (IsPerfectNumber(number))
        cout << number << " is a perfect number." << endl;
    else
        cout << number << " is NOT a perfect number." << endl;
}

int main()
{
    // Read a positive integer from the user
    int number = ReadPositiveNumber("Please enter a positive integer:");

    // Check if the number is a perfect number and print the results
    PrintResults(number);

    return 0;
}
