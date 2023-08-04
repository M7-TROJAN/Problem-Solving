#include <iostream>

bool isLeapYear(const short &year)
{
    // A year is a leap year if it is divisible by 4 AND not divisible by 100 OR if it is divisible by 400.
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short getNumberOfDaysInAMonth(const short &month, const short &year)
{
    if (month < 1 || month > 12) return 0;

    const short NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (month == 2 && isLeapYear(year))? 29 : NumberOfDays[month - 1];

    // return (month == 2) ? (isLeapYear(year) ? 29 : 28) : NumberOfDays[month - 1];
}

int main()
{
    short year, month;

    std::cout << "\nPlease enter a year: ";
    std::cin >> year;
    std::cout << "\nPlease enter a month: ";
    std::cin >> month;

    std::cout << "\nNumber of days in month [" << month << "] is " << getNumberOfDaysInAMonth(month, year);

    system("pause > nul");
    return 0;
}
