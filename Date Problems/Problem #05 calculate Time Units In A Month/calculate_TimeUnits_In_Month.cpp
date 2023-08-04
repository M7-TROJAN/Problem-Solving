#include <iostream>

bool isLeapYear(const short& year)
{
    // A year is a leap year if it is divisible by 4 AND not divisible by 100 OR if it is divisible by 400.
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short getNumberOfDaysInAMonth(const short& month, const short& year)
{
    if (month < 1 || month > 12)
        return 0;

    if (month == 2)
        return isLeapYear(year) ? 29 : 28;

    const short arr31Days[7] = {1, 3, 5, 7, 8, 10, 12};
    for (const short& m : arr31Days)
    {
        if (m == month)
            return 31;
    }

    // If we reach here, the month has 30 days.
    return 30;
}

short getNumberOfHoursInAMonth(const short& month, const short& year)
{
    return getNumberOfDaysInAMonth(month, year) * 24;
}

int getNumberOfMinutesInAMonth(const short& month, const short& year)
{
    return getNumberOfHoursInAMonth(month, year) * 60;
}

int getNumberOfSecondsInAMonth(const short& month, const short& year)
{
    return getNumberOfMinutesInAMonth(month, year) * 60;
}

int main()
{
    short year, month;

    std::cout << "\nPlease enter a year: ";
    std::cin >> year;
    std::cout << "\nPlease enter a month: ";
    std::cin >> month;

    std::cout << "\nNumber of days    in month [" << month << "] is " << getNumberOfDaysInAMonth(month, year);
    std::cout << "\nNumber of hours   in month [" << month << "] is " << getNumberOfHoursInAMonth(month, year);
    std::cout << "\nNumber of minutes in month [" << month << "] is " << getNumberOfMinutesInAMonth(month, year);
    std::cout << "\nNumber of seconds in month [" << month << "] is " << getNumberOfSecondsInAMonth(month, year);

    system("pause > nul");
    return 0;
}
