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

    // Check if the month value is valid
    if (month < 1 || month > 12)
        return 0;

    // Handle February in a leap year
    if (month == 2 && isLeapYear(year))
        return 29;
    else
        return NumberOfDays[month - 1];
}

struct stDate
{
    short day = 0;
    short month = 0;
    short year = 0;
};

stDate readDate()
{
    stDate date;
    // Get the input from the user
    std::cout << "Please enter a Day: ";
    std::cin >> date.day;
    std::cout << "Please enter a Month: ";
    std::cin >> date.month;
    std::cout << "Please enter a Year: ";
    std::cin >> date.year;

    return date;
    // Note: You must verify that the user's input is correct.
    // For example, ensure the user does not enter a day less than 1 or greater than 31,
    // and that the user does not enter a month less than 1 or greater than 12.
}

stDate IncreaseDateByOneDay(stDate &date)
{
    if(date.day == getNumberOfDaysInAMonth(date.month, date.year))
    {
        date.day = 1;
        if(date.month == 12)
        {
            date.month = 1;
            date.year++;
        }
        else
            date.month++;
    }
    else
    {
        date.day++;
    }
    return date;
}

int main()
{
    stDate date = readDate();
    date = IncreaseDateByOneDay(date);

    std::cout << "\nDate after adding one day is:" << date.day << "/" << date.month << "/" << date.year;
    system("pause > nul");
    return 0;
}

