
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
    cout << "Please enter a Day: ";
    cin >> date.day;
    cout << "Please enter a Month: ";
    cin >> date.month;
    cout << "Please enter a Year: ";
    cin >> date.year;

    return date;
    // Note: You must verify that the user's input is correct.
    // For example, ensure the user does not enter a day less than 1 or greater than 31,
    // and that the user does not enter a month less than 1 or greater than 12.
}

// Checks if a year is a leap year
bool isLeapYear(const short &year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Returns the number of days in a specific month of a year
short getNumberOfDaysInAMonth(const short &month, const short &year)
{
    if (month < 1 || month > 12) return 0;

    const short NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (month == 2 && isLeapYear(year))? 29 : NumberOfDays[month - 1];
}

bool IsLastDayInMonth(const stDate &date)
{
    return date.day == getNumberOfDaysInAMonth(date.month, date.year);
}

bool IsLastMonthInYear(const short &month)
{
    return month == 12;
}

stDate IncreaseDateByOneDay(stDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.month))
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

stDate IncreaseDateByXDays(stDate date, const short &daysToAdd)
{
    for (int i = 0; i < daysToAdd; i++)
        date = IncreaseDateByOneDay(date);
    return date;
}

stDate IncreaseDateByOneWeek(stDate date)
{
    date = IncreaseDateByXDays(date, 7);
    return date;
}

stDate IncreaseDateByXWeeks(stDate date, const short &weeksToAdd)
{
    for (int i = 0; i < weeksToAdd; i++)
        date = IncreaseDateByOneWeek(date);
    return date;
}

stDate IncreaseDateByOneMonth(stDate date)
{
    if (date.month == 12)
    {
        date.month = 1;
        date.year++;
    }
    else
    {
        date.month++;
    }

    // Note: day in date should not exceed max days in the current month
    // example if date is 31/1/2022 increasing one month should not be 31 / 2 / 2022, it should be 28/2/2022

    short NumberOfDaysInCurrentMonth = getNumberOfDaysInAMonth(date.month, date.year);
    if (date.day > NumberOfDaysInCurrentMonth)
    {
        date.day = NumberOfDaysInCurrentMonth;
    }
    return date;
}

stDate IncreaseDateByXMonths(stDate date, const short &MonthsToAdd)
{
    for (int i = 0; i < MonthsToAdd; i++)
        date = IncreaseDateByOneMonth(date);
    return date;
}

stDate IncreaseDateByOneYear(stDate date)
{
    date.year++;
    if(date.day > getNumberOfDaysInAMonth(date.month, date.year))
    {
        date.day =  getNumberOfDaysInAMonth(date.month, date.year);
    }
    return date;
}

stDate IncreaseDateByXYears(stDate date, const short &YearsToAdd)
{
    for (int i = 0; i < YearsToAdd; i++)
        date = IncreaseDateByOneYear(date);
    return date;
}

stDate IncreaseDateByXYearsFaster(stDate date, const short &YearsToAdd)
{
    date.year += YearsToAdd;
    if(date.day > getNumberOfDaysInAMonth(date.month, date.year))
    {
        date.day = getNumberOfDaysInAMonth(date.month, date.year);
    }
    return date;
}

stDate IncreaseDateByOneDecade(stDate date)
{
    const short Decade = 10;
    date.year += Decade;
    if(date.day > getNumberOfDaysInAMonth(date.month, date.year))
    {
        date.day = getNumberOfDaysInAMonth(date.month, date.year);
    }
    return date;
}

stDate IncreaseDateByXDecades(stDate date, const short &DecadesToAdd)
{
    const short totalDecades = 10 * DecadesToAdd;
    date.year += totalDecades;
    if(date.day > getNumberOfDaysInAMonth(date.month, date.year))
    {
        date.day = getNumberOfDaysInAMonth(date.month, date.year);
    }
    return date;
}

stDate IncreaseDateByOneCentury(stDate date)
{
    const short Century = 100;
    date.year += Century;
    if(date.day > getNumberOfDaysInAMonth(date.month, date.year))
    {
        date.day = getNumberOfDaysInAMonth(date.month, date.year);
    }
    return date;
}

stDate IncreaseDateByOneMillennium(stDate date)
{
    const short millennium = 1000;
    date.year += millennium;
    if(date.day > getNumberOfDaysInAMonth(date.month, date.year))
    {
        date.day = getNumberOfDaysInAMonth(date.month, date.year);
    }
    return date;
}

int main()
{
    stDate date = readDate();

    cout << "\nDate After:\n";

    date = IncreaseDateByOneDay(date);
    cout << "01- Adding One Day Is : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = IncreaseDateByXDays(date, 10);
    cout << "02- Adding 10 Days Is : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = IncreaseDateByOneWeek(date);
    cout << "03- Adding One Week Is : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = IncreaseDateByXWeeks(date, 10);
    cout << "04- Adding 10 Weeks Is : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = IncreaseDateByOneMonth(date);
    cout << "05- Adding One Month Is : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = IncreaseDateByXMonths(date, 5);
    cout << "06- Adding 5 Months Is : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = IncreaseDateByOneYear(date);
    cout << "07- Adding One Year Is : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = IncreaseDateByXYears(date, 10);
    cout << "08- Adding 10 Years Is : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = IncreaseDateByXYearsFaster(date, 10);
    cout << "09- Adding 10 Years (Faster) Is : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = IncreaseDateByOneDecade(date);
    cout << "10- Adding One Decade Is : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = IncreaseDateByXDecades(date, 10);
    cout << "11- Adding 10 Decades Is : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = IncreaseDateByOneCentury(date);
    cout << "12- Adding One Century Is : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = IncreaseDateByOneMillennium(date);
    cout << "13- Adding One Millennium Is : " << date.day << "/" << date.month << "/" << date.year << endl;

    system("pause > nul");
    return 0;
}

