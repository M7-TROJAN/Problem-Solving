#include <iostream>
using namespace std;
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