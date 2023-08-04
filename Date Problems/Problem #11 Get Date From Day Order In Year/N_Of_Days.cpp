
#include <iostream>

// Checks if a year is a leap year
bool isLeapYear(const short &year)
{
    // A year is a leap year if it is divisible by 4 AND not divisible by 100 OR if it is divisible by 400.
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Retrieves the number of days in a given month of a year
short getNumberOfDaysInAMonth(const short &month, const short &year)
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
short getNumberOfDaysFromTheBeginningOfYear(const short &day, const short &month, const short &year)
{
    short totalDays = day;
    for (int i = 1; i < month; i++)
    {
        totalDays += getNumberOfDaysInAMonth(i, year);
    }
    return totalDays;
}

struct stDate
{
    short day = 0;
    short month = 0;
    short year = 0;
};

// Retrieves the date corresponding to the given day order in a year
// If the daysOrderInYear is invalid, returns a default invalid date (0/0/0).
stDate GetDateFromDayOrderInYear(const short &daysOrderInYear, const short &year)
{
    stDate date;
    date.year = year;

    int totalDays = 0;
    for (int month = 1; month <= 12; month++)
    {
        int daysInMonth = getNumberOfDaysInAMonth(month, year);
        for (int day = 1; day <= daysInMonth; day++)
        {
            totalDays++;
            if (totalDays == daysOrderInYear)
            {
                date.day = day;
                date.month = month;
                return date;
            }
        }
    }

    // If the daysOrderInYear is invalid, return a default invalid date
    return date;
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
    // Note: You must verify that the user's input is correct.
    // For example, ensure the user does not enter a day less than 1 or greater than 31,
    // and that the user does not enter a month less than 1 or greater than 12.

    short daysOrderInYear = getNumberOfDaysFromTheBeginningOfYear(day, month, year);
    std::cout << "\nNumber of days from the beginning of the year: " << daysOrderInYear << std::endl;

    stDate date = GetDateFromDayOrderInYear(daysOrderInYear, year);

    std::cout << "\nDate for [" << daysOrderInYear << "] is: ";
    std::cout << date.day << "/" << date.month << "/" << date.year;

    system("pause > nul");
    return 0;
}
