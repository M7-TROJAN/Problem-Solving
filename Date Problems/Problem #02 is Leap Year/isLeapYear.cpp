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

bool isLeapYear(const short &year)
{
    if (year % 400 == 0)
        return true;
    if ((year % 4 == 0) && (year % 100 != 0))
        return true;
    return false;
}

int main()
{
    short year = get_int("Please Enter a Year To Check: ");

    if (isLeapYear(year))
        cout << "\nYes, Year [" <<  year << "] Is a Leap Year.\n";
    else
        cout << "\nNo, Year [" <<  year << "] Is Not a Leap Year.\n";

    cin.get();
    return 0;
}

/*
    leap year if perfectly divisible by 400
    if (Year % 400 == 0)
    {
        return true;
    }

    not a leap year if divisible by 100
    but not divisible by 400
    else if (Year % 100 == 0)
    {
        return false;
    }

    leap year if not divisible by 100 but divisible by 4
    else if (Year % 4 == 0)
    {
        return true;
    }

    all other years are not leap years
    else
    {
        return false;
    }
*/
