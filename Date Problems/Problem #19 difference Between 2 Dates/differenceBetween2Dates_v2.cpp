
#include <iostream>
using namespace std;

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

// Checks if a year is a leap year
bool isLeapYear(const short &year)
{
    // A year is a leap year if it is divisible by 4 AND not divisible by 100 OR if it is divisible by 400.
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short numberOfDaysInAYear(short Year)
{
    return isLeapYear(Year) ? 366 : 365;
}

bool isDate1BeforeDate2(const stDate &date1, const stDate &date2)
{
    if (date1.year < date2.year)
        return true;
    if (date1.year > date2.year)
        return false;

    if (date1.month < date2.month)
        return true;
    if (date1.month > date2.month)
        return false;

    if (date1.day < date2.day)
        return true;

    return false;
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

void swapDates(stDate &date1, stDate &date2)
{
    stDate temp = date1;
    date1 = date2;
    date2 = temp;
}

// Function to calculate the difference in days between two dates
int differenceBetween2Dates(stDate date1, stDate date2, bool includeEndDay = false)
{
    int differenceInDays = 0;
    short SwapFlagValue = 1;
    if (!isDate1BeforeDate2(date1, date2))
    {
        // Swap Dates
        swapDates(date1, date2);
        SwapFlagValue = -1;
    }

    // Calculate the remaining days in date2's year by subtracting the days passed from the beginning of the year
    int remainingDaysInYear2 = numberOfDaysInAYear(date2.year) - getNumberOfDaysFromTheBeginningOfYear(date2.day, date2.month, date2.year);

    // Check if date1 is before date2
    if (isDate1BeforeDate2(date1, date2))
    {
        // Calculate the difference in days by iterating over each year between date1 and date2
        for (short year = date1.year; year <= date2.year; year++)
        {
            differenceInDays += numberOfDaysInAYear(year);
        }

        // Subtract the remaining days in date2's year and the days from the beginning of date1's year
        differenceInDays -= remainingDaysInYear2 + getNumberOfDaysFromTheBeginningOfYear(date1.day, date1.month, date1.year);
    }

    return includeEndDay ? (++differenceInDays * SwapFlagValue) : (differenceInDays * SwapFlagValue);
}

int main()
{
    stDate date1 = readDate();
    cout << endl;
    stDate date2 = readDate();

    cout << "\nDifference is: " << differenceBetween2Dates(date1, date2) << " Day(s).";

    system("pause > nul");
    return 0;
}
