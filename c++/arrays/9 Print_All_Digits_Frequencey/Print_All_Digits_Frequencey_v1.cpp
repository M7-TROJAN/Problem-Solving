/*
    This code reads a positive integer from the user, counts the frequency of each digit in the number,
    and prints the frequency of each digit.
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

// This function updates the frequency of each digit in the given number.
void CountDigitsFrequency(int FreqCount[] , int Number)
{
    int Remainder = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;  // Get the remainder of the number when divided by 10.
        Number = Number / 10;     // Divide the number by 10 to remove the last digit.

        // Update the frequency count of the current digit.
        switch (Remainder)
        {
        case 0:
            FreqCount[0]++;
            break;
        case 1:
            FreqCount[1]++;
            break;
        case 2:
            FreqCount[2]++;
            break;
        case 3:
            FreqCount[3]++;
            break;
        case 4:
            FreqCount[4]++;
            break;
        case 5:
            FreqCount[5]++;
            break;
        case 6:
            FreqCount[6]++;
            break;
        case 7:
            FreqCount[7]++;
            break;
        case 8:
            FreqCount[8]++;
            break;
        case 9:
            FreqCount[9]++;
            break;
        }
    }
}

int main()
{
    int Number = ReadPositiveNumber("Please enter the main number?"); // Get a positive integer from the user.

    int FreqCount[10] = {0};  // Initialize an array to store the frequency count of each digit.

    CountDigitsFrequency(FreqCount, Number);  // Update the frequency count of each digit in the given number.

    cout << "===============================\n";
    for (short i = 0; i < 10; i++)
    {
        if (FreqCount[i] < 1)  // If the frequency of the current digit is less than 1, skip to the next digit.
            continue;
        cout << "Digit " << i << " Frequency is " << FreqCount[i] << " Time(s)." << endl;  // Print the frequency of the current digit.
    }

    return 0;
}
