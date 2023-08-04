
#include <iostream>

// Checks if a year is a leap year
bool isLeapYear(const short& year)
{
    // A year is a leap year if it is divisible by 4 AND not divisible by 100 OR if it is divisible by 400.
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Retrieves the number of days in a given month of a year
short getNumberOfDaysInAMonth(const short& month, const short& year)
{
    const short NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month < 1 || month > 12)
        return 0;

    if (month == 2 && isLeapYear(year))
        return 29;
    else
        return NumberOfDays[month - 1];
}

// Calculates the number of days from the beginning of the year
short getNumberOfDaysFromTheBeginningOfYear(const short& day, const short& month, const short& year)
{
    short totalDays = day;
    for (int i = 1; i < month; i++)
    {
        totalDays += getNumberOfDaysInAMonth(i, year);
    }
    return totalDays;
}

int main()
{
    short day, month, year;

    std::cout << "Please enter a Day: ";
    std::cin >> day;
    std::cout << "Please enter a Month: ";
    std::cin >> month;
    std::cout << "Please enter a Year: ";
    std::cin >> year;

    std::cout << "\nNumber of days from the beginning of the year: " << getNumberOfDaysFromTheBeginningOfYear(day, month, year) << std::endl;
    system("pause > nul");
    return 0;
}


/*

short numberOfDaysFromTheBeginningOfTheYear(const short &day, const short &month, const short &year)
{
    short totalDays = 0;
    for (int i = 1; i <= month - 1; i++)
    {
        totalDays += getNumberOfDaysInAMonth(i, year);
    }
    totalDays += day;
    return totalDays;
}

*/


/*
short numberOfDaysFromTheBeginningOfTheYear(const short &day, const short &month, const short &year)
{
    short totalDays = day;
    for (int i = month - 1; i >= 1; i--)
    {
        totalDays += getNumberOfDaysInAMonth(i, year);
    }

    return totalDays;
}

*/