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

enDateCompare compDates(stDate date1, stDate date2)
{
    if (IsDate1EqualDate2(date1, date2))
        return enDateCompare::Equal;
    if (IsDate1AfterDate2(date1, date2))
        return enDateCompare::After;
    return enDateCompare::Before;
}


// This function checks if a given date falls within a specified period
bool isDateInPeriod(const stDate &Date, const stPeriod &Period)
{
    return !(compDates(Date, Period.StartDate) == enDateCompare::Before || compDates(Date, Period.EndDate) == enDateCompare::After);
}

int main()
{
    cout << "\nEnter Period :";
    stPeriod Period = ReadPeriod();
    cout << "\nEnter Date to check:\n";
    stDate Date = readDate();
    if (isDateInPeriod(Date, Period))
        cout << "\nYes, Date is within period\n";
    else
        cout << "\nNo, Date is NOT within period\n";
    system("pause > nul");
    return 0;
}