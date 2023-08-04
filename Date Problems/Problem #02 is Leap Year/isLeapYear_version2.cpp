/*
Note:
All years which are perfectly divisible by 4 are leap years except for century years (years ending with 00),
which are leap years only if they are perfectly divisible by 400.
*/
#include <iostream>
#include <string>
#include <limits>
using namespace std;

int get_int(const string &message = "")
{
    int number = 0;
    do
    {
        // Read an integer value from the user
        cout << message;
        cin >> number;

        // Check if the input was invalid (i.e. not an integer)
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // cout << "Invalid input. Please enter a valid integer.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;
    } while (true);
    return number;
}

bool isLeapYear(short Year)
{
    // if year is divisible by 4 AND not divisible by 100 OR if it's divisible by 400 then it is a leap year
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

int main()
{
    short year = get_int("Please Enter a Year To Check: ");

    if (isLeapYear(year))
        cout << "\nYes, Year [" << year << "] Is a Leap Year.\n";
    else
        cout << "\nNo, Year [" << year << "] Is Not a Leap Year.\n";

    cin.get();
    return 0;
}