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

// Determines if the given year is a leap year
// Leap year if year is divisible by 4 AND not divisible by 100 OR if it's divisible by 400
bool isLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

// Returns the number of days in a specific month of a year
short getNumberOfDaysInAMonth(const short &month, const short &year)
{
    if (month < 1 || month > 12)
        return 0;

    const short NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (month == 2 && isLeapYear(year)) ? 29 : NumberOfDays[month - 1];
}

// Checks if the day in the given date is the last day of the month
bool IsLastDayInMonth(const stDate &date)
{
    return date.day == getNumberOfDaysInAMonth(date.month, date.year);
}

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

// Increases the given date by one day
stDate IncreaseDateByOneDay(stDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (Date.month == 12)
        {
            Date.month = 1;
            Date.day = 1;
            Date.year++;
        }
        else
        {
            Date.day = 1;
            Date.month++;
        }
    }
    else
    {
        Date.day++;
    }
    return Date;
}

// this function calculate the difference Between two Dates in days
int getDifferenceBetween2Dates(stDate date1, stDate date2, bool IncludeEndDay = false)
{
    int differenceInDays = 0;
    while (IsDate1BeforeDate2(date1, date2))
    {
        differenceInDays++;
        date1 = IncreaseDateByOneDay(date1);
    }
    return IncludeEndDay ? ++differenceInDays : differenceInDays;
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

// This function calculates the length of a period in days.
int PeriodLengthInDays(stPeriod Period, bool IncludeEndDate = false)
{
    return getDifferenceBetween2Dates(Period.StartDate, Period.EndDate, IncludeEndDate);
}

int main()
{

    cout << "\nEnter Period:";
    stPeriod period = ReadPeriod();

    cout << "\nPeriod Length is: " << PeriodLengthInDays(period);
    cout << "\nPeriod Length (Including End Date) is: " << PeriodLengthInDays(period, true);
    system("pause > nul");

    return 0;
}