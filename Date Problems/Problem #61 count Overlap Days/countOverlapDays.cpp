#include <iostream>
using namespace std;

struct stDate
{
    short day;
    short month;
    short year;
};

struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
};

enum enDateCompare
{
    Before = -1,
    Equal = 0,
    After = 1
};

// Reads a date from the user by separately requesting the day, month, and year.
// Returns a stDate structure representing the entered date.
stDate readDate()
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

stPeriod ReadPeriod()
{
    stPeriod Period;
    std::cout << "\nEnter Start Date:\n";
    Period.StartDate = readDate();
    std::cout << "\nEnter End Date:\n";
    Period.EndDate = readDate();
    return Period;
}

// Checks if a year is a leap year
bool isLeapYear(const short &year)
{
    // A year is a leap year if it is divisible by 4 AND not divisible by 100 OR if it is divisible by 400.
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Returns the number of days in a year
short NumberOfDaysInAYear(const short &Year) 
{ 
    return isLeapYear(Year) ? 366 : 365; 
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

// Calculates the number of days from the beginning of the year until the specified date
short getNumberOfDaysFromTheBeginningOfYear(stDate date)
{
    short totalDays = date.day;
    for (int i = 1; i < date.month; i++)
    {
        totalDays += getNumberOfDaysInAMonth(i, date.year);
    }
    return totalDays;
}

// Checks if date1 is before date2
bool IsDate1BeforeDate2(const stDate &date1, const stDate &date2)
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

// Checks if date1 is Equal to date2
bool IsDate1EqualDate2(const stDate &date1, const stDate &date2)
{
    return date1.year == date2.year && date1.month == date2.month && date1.day == date2.day;
}

// Checks if date1 is after date2
bool IsDate1AfterDate2(const stDate &date1, const stDate &date2)
{
    return (!IsDate1BeforeDate2(date1, date2) && !IsDate1EqualDate2(date1, date2));
}

// Swaps the values of two stDate variables.
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
    if (!IsDate1BeforeDate2(date1, date2))
    {
        // Swap Dates
        swapDates(date1, date2);
        SwapFlagValue = -1;
    }
    // Check if date1 is before date2
    if (IsDate1BeforeDate2(date1, date2))
    {
        // Check if date1 and date2 have the same year
        if (date1.year == date2.year)
        {
            differenceInDays = getNumberOfDaysFromTheBeginningOfYear(date2) - getNumberOfDaysFromTheBeginningOfYear(date1);
        }

        else
        {
            // Calculate the remaining days in year2 by subtracting the days passed from the beginning of year2
            int remainingDaysInYear2 = NumberOfDaysInAYear(date2.year) - getNumberOfDaysFromTheBeginningOfYear(date2);

            // Calculate the difference in days by iterating over each year between date1 and date2
            for (short year = date1.year; year <= date2.year; year++)
            {
                differenceInDays += NumberOfDaysInAYear(year);
            }

            // Subtract the remaining days in year2 and the days from the beginning of date1's year
            differenceInDays -= remainingDaysInYear2 + getNumberOfDaysFromTheBeginningOfYear(date1);
        }
        
    }
    return includeEndDay ? (++differenceInDays * SwapFlagValue) : (differenceInDays * SwapFlagValue);
}

enDateCompare compDates(stDate date1, stDate date2)
{
    if (IsDate1EqualDate2(date1, date2))
        return enDateCompare::Equal;
    if (IsDate1AfterDate2(date1, date2))
        return enDateCompare::After;
    return enDateCompare::Before;
}

// Function to check if two periods overlap
bool isOverlapPeriods(stPeriod period1, stPeriod period2)
{
    if (compDates(period2.EndDate, period1.StartDate) == enDateCompare::Before ||
        compDates(period2.StartDate, period1.EndDate) == enDateCompare::After)
        return false;
    return true;
}

// Returns the minimum date between two dates
stDate MinDate(stDate date1 , stDate date2)
{
    return IsDate1BeforeDate2(date1, date2)? date1 : date2;
}

// Returns the maximum date between two dates
stDate MaxDate(stDate date1 , stDate date2)
{
    return IsDate1BeforeDate2(date1, date2)? date2 : date1;
}

// Counts the number of overlapping days between two periods
int countOverlapDays(const stPeriod &period1, const stPeriod &period2)
{
    // Check if the two periods do not overlap
    if (!isOverlapPeriods(period1, period2))
        return 0;

    // Determine the earliest end date between the two periods
    stDate minPeriodEndDate   = MinDate(period1.EndDate, period2.EndDate);
    // Determine the latest start date between the two periods
    stDate maxPeriodStartDate = MaxDate(period1.StartDate, period2.StartDate);

    // Calculate the difference in days between the earliest end date and the latest start date.
    int diffDays = differenceBetween2Dates(minPeriodEndDate, maxPeriodStartDate, true);

    return diffDays < 0 ? diffDays * -1 : diffDays;
}

int main()
{
    cout << "\nEnter Period 1";
    stPeriod period1 = ReadPeriod();

    cout << "\n====================\n";

    cout << "\nEnter Period 2";
    stPeriod period2 = ReadPeriod();

    cout << "\nOverlap Days Count Is: " << countOverlapDays(period1, period2);

    system("pause > nul");
    return 0;
}
