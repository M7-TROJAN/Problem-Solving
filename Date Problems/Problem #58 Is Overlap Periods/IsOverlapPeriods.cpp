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

bool IsDate1AfterDate2(const stDate &date1, const stDate &date2)
{
    return (!IsDate1BeforeDate2(date1, date2) && !IsDate1EqualDate2(date1, date2));
}

// compDates function compares two dates and returns an enDateCompare value based on the comparison.
// If date1 is before date2, it returns enDateCompare::Before.  -1
// If date1 is equal to date2, it returns enDateCompare::Equal.  0
// If date1 is after date2, it returns enDateCompare::After.     1
enDateCompare compDates(stDate date1, stDate date2)
{
    if (IsDate1EqualDate2(date1, date2)) 
        return enDateCompare::Equal;
    if(IsDate1AfterDate2(date1, date2)) 
        return enDateCompare::After;
    return enDateCompare::Before;
}

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
    cout << "\nEnter Start Date:\n";
    Period.StartDate = readDate();
    cout << "\nEnter End Date:\n";
    Period.EndDate = readDate();
    return Period;
}

// Function to check if two periods overlap
bool isOverlapPeriods(stPeriod period1, stPeriod period2)
{
    if (compDates(period2.EndDate, period1.StartDate) == enDateCompare::Before ||
    compDates(period2.StartDate, period1.EndDate) == enDateCompare::After)
        return false;
    return true;
}

int main()
{

    cout << "\nEnter Period 1";
    stPeriod period1 = ReadPeriod();

    cout << "\nEnter Period 2";
    stPeriod period2 = ReadPeriod();

    if (isOverlapPeriods(period1, period2))
        cout << "\nYes, Periods Overlap\n";
    else
        cout << "\nNo, Periods Don't Overlap\n";

    system("pause > nul");
    return 0;
}

// from 25 / 1 / 2001  to  31 / 1 / 2001
// from 11 / 1 / 2001  to  20 / 1 / 2001