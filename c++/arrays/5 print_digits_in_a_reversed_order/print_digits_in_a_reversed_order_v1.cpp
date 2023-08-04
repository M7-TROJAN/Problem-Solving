
#include <iostream>
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
int main()
{
    int number = ReadPositiveNumber("Please enter a positive integer:");

    // Convert the integer to a string
    string numberString = to_string(number);

    // Reverse the order of the characters in the string and print the result
    int n = numberString.length()-1; // Get the index of the last character in the string
    for (int i = n; i >= 0; i--) // Iterate over the characters in the string from the last to the first
    {
        cout << numberString[i]; // Print each character
    }
    cout << "\n";

    return 0;
}