#include <iostream>
using namespace std;

bool isLeapYear(short Year)
{
    // if year is divisible by 4 AND not divisible by 100 OR if it's divisible by 400 then it is a leap year
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAYear(short Year) 
{ 
    return isLeapYear(Year) ? 366 : 365; 
}
short NumberOfHoursInAYear(short Year)
{
    return NumberOfDaysInAYear(Year) * 24;
}
int NumberOfMinutesInAYear(short Year)
{
    return NumberOfHoursInAYear(Year) * 60;
}
int NumberOfSecondsInAYear(short Year)
{
    return NumberOfMinutesInAYear(Year) * 60;
}

int main()
{
    short Year;
    cout << "\nPlease enter a year to check: ";
    cin >> Year;

    cout << "\nNumber of Days    in Year [" << Year << "] is " << NumberOfDaysInAYear(Year);
    cout << "\nNumber of Hours   in Year [" << Year << "] is " << NumberOfHoursInAYear(Year);
    cout << "\nNumber of Minutes in Year [" << Year << "] is " << NumberOfMinutesInAYear(Year);
    cout << "\nNumber of Seconds in Year [" << Year << "] is " << NumberOfSecondsInAYear(Year);

    system("pause > nul");
    return 0;
}