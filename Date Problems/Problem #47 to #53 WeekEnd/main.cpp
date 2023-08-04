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

// Returns the number of days in a year
short NumberOfDaysInAYear(short Year) 
{ 
    return isLeapYear(Year) ? 366 : 365; 
}

// Returns the number of days in a specific month of a year
short getNumberOfDaysInAMonth(const short &month, const short &year)
{
    if (month < 1 || month > 12) return 0;

    const short NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (month == 2 && isLeapYear(year))? 29 : NumberOfDays[month - 1];
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

bool IsEndOfWeek(stDate date)
{
    return calculateDayOfWeekOrder(date) == 6;
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
    return  ! IsWeekEnd(date);
}

short daysUntilTheEndOfWeek(stDate date)
{
    return 7 - (calculateDayOfWeekOrder(date) + 1);
}

short daysUntilTheEndOfMonth(stDate date, bool IncludeCurrentDay = false)
{
    if(IncludeCurrentDay)
        return getNumberOfDaysInAMonth(date.month, date.year) - date.day + 1;
    
    return getNumberOfDaysInAMonth(date.month, date.year) - date.day;
}

short daysUntilTheEndOfYear(stDate date, bool IncludeCurrentDay = false)
{
    if(IncludeCurrentDay)
        return NumberOfDaysInAYear(date.year) - getNumberOfDaysFromTheBeginningOfYear(date) + 1;
    
    return NumberOfDaysInAYear(date.year) - getNumberOfDaysFromTheBeginningOfYear(date);
}

// Function to get the current system date
stDate getSystemDate()
{
    time_t currentTime = time(0);
    tm *now = localtime(&currentTime);
    stDate currentDate;

    currentDate.day = now->tm_mday;
    currentDate.month = now->tm_mon + 1;
    currentDate.year = now->tm_year + 1900;

    return currentDate;
}

int main()
{
    stDate date = getSystemDate();
    cout << "\nToday is:\n\n";
    cout << getDayShortName(calculateDayOfWeekOrder(date)) << ", " 
        << date.day << "/" << date.month << "/" << date.year << endl;

    //__________________________________________________________________________________________________________

    cout << "\nIs it End of Week?\n";
    if (IsEndOfWeek(date))
        cout << "Yes it is Saturday, it's End of Week.";
    else
        cout << "No it's Not end of week.";

    //__________________________________________________________________________________________________________

    cout << "\n\nIs it Weekend?\n";
    if (IsWeekEnd(date))
        cout << "Yes it is a week end.";
    else
        cout << "No [" << getDayShortName(calculateDayOfWeekOrder(date)) << "] Is Not a Weekend." ;

    //__________________________________________________________________________________________________________

    cout << "\n\nIs it Business Day?\n"; 
    if (IsBusinessDay(date)) 
        cout << "Yes it is a business day."; 
    else
        cout << "No it is NOT a business day.";

    //__________________________________________________________________________________________________________

    cout << "\n\nDays until end of week : " << daysUntilTheEndOfWeek(date) << " Day(s)."; 

    //__________________________________________________________________________________________________________

    cout << "\nDays until end of month : " << daysUntilTheEndOfMonth(date, true) << " Day(s).";

    //__________________________________________________________________________________________________________

    cout << "\nDays until end of year : " << daysUntilTheEndOfYear(date, true) << " Day(s).";

    system("pause > nul");
    return 0;
}
