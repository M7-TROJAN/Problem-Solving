
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

stDate dateAddDays(stDate date, const int &daysToAdd)
{
    // Calculate the total number of days by adding the given days to the days from the beginning of the year
    int totalDays = getNumberOfDaysFromTheBeginningOfYear(date.day, date.month, date.year) + daysToAdd;

    // Start with the initial date values
    stDate result = date;

    // Iterate through each month and subtract the days in the month until the remaining days are less than or equal to zero
    for (int month = 1; month <= 12; month++)
    {
        int daysInMonth = getNumberOfDaysInAMonth(month, result.year);

        if (totalDays <= daysInMonth)
        {
            // If the remaining days are within the current month, update the result and break the loop
            result.day = totalDays;
            result.month = month;
            break;
        }

        // Subtract the days in the month from the total days and continue to the next month
        totalDays -= daysInMonth;

        // If the current month is greater than 12, increment the year and reset the month to 1
        if (month == 12)
        {
            result.year++;
            month = 0; // It will be incremented to 1 in the next iteration
        }
    }

    return result;
}


int main()
{
    stDate date;
    std::cout << "Please enter a Day: ";
    std::cin >> date.day;
    std::cout << "Please enter a Month: ";
    std::cin >> date.month;
    std::cout << "Please enter a Year: ";
    std::cin >> date.year;
    // Note: You must verify that the user's input is correct.
    // For example, ensure the user does not enter a day less than 1 or greater than 31,
    // and that the user does not enter a month less than 1 or greater than 12.

    int daysToAdd = 0;
    std::cout << "\nHow Many Days To Add?: ";
    std::cin >> daysToAdd;

    date = dateAddDays(date, daysToAdd);

    std::cout << "\nDate after adding [" << daysToAdd << "] days is: ";
    std::cout << date.day << "/" << date.month << "/" << date.year << "\n";

    system("pause > nul");
    return 0;
}
