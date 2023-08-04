#include <iostream>
using namespace std;
struct stDate
{
    short day;
    short month;
    short year;
};

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

// Calculates the day of the week (0: Sunday, 1: Monday, ..., 6: Saturday) using the Gregorian Calendar formula
short calculateDayOfWeekOrder(stDate date)
{
    short a, y, m;

    a = (14 - date.month) / 12;
    y = date.year - a;
    m = date.month + (12 * a) - 2;

    // Calculate the day of the week using Gregorian Calendar formula
    // Gregorian (ميلادي) => 0: Sun, 1: Mon, 2: Tue, ... , 6: Sat
    return (date.day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

std::string getDayShortName(short dayOfWeekOrder)
{
    const std::string arrDayNames[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return arrDayNames[dayOfWeekOrder];
}

bool IsWeekEnd(stDate date)
{
    // Weekends in are Fri and Sat, index of fri is 5 and sat is 6.
    short dayIndex = calculateDayOfWeekOrder(date);
    return (dayIndex == 5 || dayIndex == 6);
}

bool IsBusinessDay(stDate date)
{
    // Business days are all days except Friday and Saturday.
    return !IsWeekEnd(date);
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
stDate IncreaseDateByOneDay(stDate date)
{
    if (date.day == getNumberOfDaysInAMonth(date.month, date.year))
    {
        if (date.month == 12)
        {
            date.month = 1;
            date.day = 1;
            date.year++;
        }
        else
        {
            date.day = 1;
            date.month++;
        }
    }
    else
    {
        date.day++;
    }
    return date;
}

short calculateVacationDays(stDate dateFrom, const stDate &dateTo)
{
    if( ! IsDate1BeforeDate2(dateFrom, dateTo)) return 0;

    short DaysCount = 0;
    while (IsDate1BeforeDate2(dateFrom, dateTo))
    {
        if (IsBusinessDay(dateFrom))
            DaysCount++;
        dateFrom = IncreaseDateByOneDay(dateFrom);
    }

    // Add 1 to the count because the loop ends when VacationStarts is equal to VacationEnds
    return DaysCount + 1 ;
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

int main()
{
    stDate VacationStarts, VacationEnds;

    cout << "\nVacation Starts:\n";
    VacationStarts = readDate();

    cout << endl;

    cout << "Vacation Ends:\n";
    VacationEnds = readDate();

    cout << endl;

    cout << "Vacation From: " << getDayShortName(calculateDayOfWeekOrder(VacationStarts)) << ", "
         << VacationStarts.day << "/" << VacationStarts.month << "/" << VacationStarts.year << endl;

    cout << "Vacation To  : " << getDayShortName(calculateDayOfWeekOrder(VacationEnds)) << ", "
         << VacationEnds.day << "/" << VacationEnds.month << "/" << VacationEnds.year << endl;

    cout << endl;

    cout << "\n\nActual Vacation Days is: " << calculateVacationDays(VacationStarts, VacationEnds);
    system("pause > nul");
    return 0;
}
