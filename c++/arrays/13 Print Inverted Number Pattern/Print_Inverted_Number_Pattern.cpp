/*
    Write a program to read a number and print inverted pattern as follows?

    Input:                            Input:
    3                                 5

    Output:                           Output:
    1                                 1
    22                                22
    333                               333
                                      4444
                                      55555
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
void PrintNumberPattern(int Number)
{
    cout << "=========================\n";
    for (int i = 1; i <= Number; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
}
int main()
{
    int number = ReadPositiveNumber("Please enter a positive number?");
    PrintNumberPattern(number); 
    return 0;
}