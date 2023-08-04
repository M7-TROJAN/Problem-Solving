#include <iostream>
#include <string>
#include <limits>
#include <tuple>
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

tuple<int, int, int, int> calculateTimeUnitsInAYear(short year)
{
    int days, hours, minutes, seconds;

    if(isLeapYear(year))
    {
        days  = 366;
        hours = days * 24; 
        minutes = hours * 60;
        seconds = minutes * 60;
    }
    else
    {
        days  = 365;
        hours = days * 24; 
        minutes = hours * 60;
        seconds = minutes * 60;
    }
    return make_tuple(days, hours, minutes, seconds);
}

int main()
{
    short year = get_int("\nPlease Enter a Year: ");

    tuple result = calculateTimeUnitsInAYear(year);
    int days, hours, minutes, seconds;
    tie(days, hours, minutes, seconds) = result;

    cout << "================================\n";
    cout << "Number Of Days    IS: " << days << "\n";
    cout << "Number Of Hours   IS: " << hours << "\n";
    cout << "Number Of Minutes IS: " << minutes << "\n";
    cout << "Number Of Seconds IS: " << seconds << "\n";
    cout << "================================\n";

    cin.get();
    return 0;
}