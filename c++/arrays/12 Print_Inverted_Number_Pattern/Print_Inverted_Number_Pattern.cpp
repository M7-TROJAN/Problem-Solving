/*
    Write a program to read a number and print inverted pattern as follows?

    Input:                            Input:
    3                                 5

    Output:                           Output:
    333                               55555
    221                               4444
    1                                 333
                                      22
                                      1
*/

#include <iostream>
using namespace std;

// This function reads a positive integer from the user and returns it
int ReadPositiveNumber(const string &message)
{
    int number = 0;
    do
    {
        cout << message << endl;

        cin >> number;

        // Check if the input was invalid (i.e. not an integer)
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
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
void PrintInvertedNumberPattern(int Number)
{
    cout << "=========================\n";
    for (int i = Number; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
}
int main()
{
    int number = ReadPositiveNumber("Please enter a positive number?");
    PrintInvertedNumberPattern(number); 
    return 0;
}