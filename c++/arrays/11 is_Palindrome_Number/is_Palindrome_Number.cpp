/*
    Write a program to read a number and check if it is Palindrome?
    Palindrome is a number that reads the same from right to left.

    Input:
        1234
        12321

    Output:
        No It's Not A Palindrome Number
        Yes It's A Palindrome Number
*/

#include <iostream>
using namespace std;

// This function reads a positive integer from the user and returns it
int readPositiveNumber(const string& message)
{
    int number = 0;
    do
    {
        cout << message << endl;
        cin >> number;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a valid integer." << endl;
        }
        else if (number <= 0)
        {
            cout << "Invalid input. Please enter a positive integer." << endl;
        }
    } while (number <= 0);

    return number;
}

// This function checks if the number is a palindrome or not
bool isPalindromeNumber(int number)
{
    int reversedNumber = 0, remainder = 0, temp = number;
    while (temp > 0)
    {
        remainder = temp % 10;
        temp /= 10;
        reversedNumber = reversedNumber * 10 + remainder;
    }

        cout << "=============================\n";
    // Check if the number is equal to its reversed form
    if (number == reversedNumber)
    {
        cout << number << " is a palindrome number." << endl;
        return true;
    }
    else
    {
        cout << number << " is not a palindrome number." << endl;
        return false;
    }
}

int main()
{
    int number = readPositiveNumber("Please enter a positive number:");
    isPalindromeNumber(number);
    return 0;
}
