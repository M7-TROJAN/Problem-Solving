
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

bool IsLastDayInMonth(const stDate &date)
{
    return date.day == getNumberOfDaysInAMonth(date.month, date.year);
}

bool IsLastMonthInYear(const short &month)
{
    return month == 12;
}

stDate IncreaseDateByOneDay(stDate &date)
{
    if (date.day == getNumberOfDaysInAMonth(date.month, date.year))
    {
        date.day = 1;
        if (date.month == 12)
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

int main()
{
    stDate date1 = readDate();
    cout << endl;
    stDate date2 = readDate();

    cout << "\nDifference is: " << getDifferenceBetween2Dates(date1, date2) << " Day(s).";
    cout << "\nDifference (Including End Day) is: " << getDifferenceBetween2Dates(date1, date2, true) << " Day(s).";

    system("pause > nul");
    return 0;
}