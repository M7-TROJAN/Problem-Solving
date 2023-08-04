#include <iostream>
using namespace std;

struct stDate
{
    short day;
    short month;
    short year;
};

// Reads a date from the user by separately requesting the day, month, and year.
// Returns a stDate structure representing the entered date.
stDate readDateOldVersion()
{
    stDate date;
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

// Validates a given date by checking if the day, month, and year components are within valid ranges.
// Returns true if the date is valid, false otherwise.
bool isValidDate(stDate date)
{
    bool isDayValid = (date.day <= getNumberOfDaysInAMonth(date.month, date.year) && date.day > 0);
    // Ensure the day is less than or equal to the number of days in the given month and year,
    // and greater than 0 to eliminate negative or zero values.

    bool isMonthValid = (date.month <= 12 && date.month > 0);
    // Ensure the month is within the range of valid months, from 1 to 12.

    bool isYearValid = (date.year >= 1);
    // Ensure the year is greater than or equal to 1.

    // Return the overall result of the date validation
    return isDayValid && isMonthValid && isYearValid;
}

int main()
{
    stDate date = readDateOldVersion();

    if (isValidDate(date))
        cout << "\nYes, Date is a valid date.\n";
    else
        cout << "\nNo, Date is a NOT valid date\n";

    system("pause > nul");
    return 0;
}
