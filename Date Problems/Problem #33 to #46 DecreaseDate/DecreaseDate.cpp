
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

bool IsFirstDayInMonth(const short &day)
{
    return day == 1;
}

bool IsFirstMonthInYear(const short &month)
{
    return month == 1;
}

stDate DecreaseDateByOneDay(stDate Date)
{
    if (IsFirstDayInMonth(Date.day))
    {
        if (IsFirstMonthInYear(Date.month))
        {
            Date.month = 12;
            --Date.year;
            Date.day = getNumberOfDaysInAMonth(Date.month, Date.year);
        }
        else
        {
            --Date.month;
            Date.day = getNumberOfDaysInAMonth(Date.month, Date.year);;
        }
    }
    else
    {
        --Date.day;
    }
    return Date;
}

stDate DecreaseDateByXDays(stDate date, const short &numberOfDays)
{
    for (int i = 0; i < numberOfDays; i++)
        date = DecreaseDateByOneDay(date);
    return date;
}

stDate DecreaseDateByOneWeek(stDate date)
{
    date = DecreaseDateByXDays(date, 7);
    return date;
}

stDate DecreaseDateByXWeeks(stDate date, const short &numberOfWeeks)
{
    for (int i = 0; i < numberOfWeeks; i++)
        date = DecreaseDateByOneWeek(date);
    return date;
}

stDate DecreaseDateByOneMonth(stDate date)
{
    if (date.month == 1)
    {
        date.month = 12;
        date.year--;
    }
    else
    {
        date.month--;
    }

    // Note: day in date should not exceed max days in the current month
    // example if date is 31/3/2022 Decreasing one month should not be 31 / 2 / 2022, it should be 28/2/2022

    short NumberOfDaysInCurrentMonth = getNumberOfDaysInAMonth(date.month, date.year);
    if (date.day > NumberOfDaysInCurrentMonth)
    {
        date.day = NumberOfDaysInCurrentMonth;
    }
    return date;
}

stDate DecreaseDateByXMonths(stDate date, const short &numberOfMonths)
{
    for (int i = 0; i < numberOfMonths; i++)
        date = DecreaseDateByOneMonth(date);
    return date;
}

stDate DecreaseDateByOneYear(stDate date)
{
    date.year--;
    if(date.day > getNumberOfDaysInAMonth(date.month, date.year))
    {
        date.day =  getNumberOfDaysInAMonth(date.month, date.year);
    }
    return date;
}

stDate DecreaseDateByXYears(stDate date, const short &numberOfYears)
{
    date.year -= numberOfYears;
    if(date.day > getNumberOfDaysInAMonth(date.month, date.year))
    {
        date.day = getNumberOfDaysInAMonth(date.month, date.year);
    }
    return date;
}

stDate DecreaseDateByXYearsFaster(stDate date, const short &numberOfYears)
{
    date.year -= numberOfYears;
    if(date.day > getNumberOfDaysInAMonth(date.month, date.year))
    {
        date.day = getNumberOfDaysInAMonth(date.month, date.year);
    }
    return date;
}

stDate DecreaseDateByOneDecade(stDate date)
{
    const short Decade = 10;
    date.year -= Decade;
    if(date.day > getNumberOfDaysInAMonth(date.month, date.year))
    {
        date.day = getNumberOfDaysInAMonth(date.month, date.year);
    }
    return date;
}

stDate DecreaseDateByXDecades(stDate date, const short &numberOfDecades)
{
    const short totalDecades = 10 * numberOfDecades;
    date.year -= totalDecades;
    if(date.day > getNumberOfDaysInAMonth(date.month, date.year))
    {
        date.day = getNumberOfDaysInAMonth(date.month, date.year);
    }
    return date;
}

stDate DecreaseDateByOneCentury(stDate date)
{
    const short Century = 100;
    date.year -= Century;
    if(date.day > getNumberOfDaysInAMonth(date.month, date.year))
    {
        date.day = getNumberOfDaysInAMonth(date.month, date.year);
    }
    return date;
}

stDate DecreaseDateByOneMillennium(stDate date)
{
    const short millennium = 1000;
    date.year -= millennium;
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

    date =  DecreaseDateByOneDay(date);
    cout << "01- Subtracting One Day Is : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DecreaseDateByXDays(date, 10);
    cout << "02- Subtracting 10 Days Is : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DecreaseDateByOneWeek(date);
    cout << "03- Subtracting One Week Is : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DecreaseDateByXWeeks(date, 10);
    cout << "04- Subtracting 10 Weeks Is : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DecreaseDateByOneMonth(date);
    cout << "05- Subtracting One Month Is : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DecreaseDateByXMonths(date, 5);
    cout << "06- Subtracting 5 Months Is : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DecreaseDateByOneYear(date);
    cout << "07- Subtracting One Year Is : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DecreaseDateByXYears(date, 10);
    cout << "08- Subtracting 10 Years Is : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DecreaseDateByXYearsFaster(date, 10);
    cout << "09- Subtracting 10 Years (Faster) Is : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DecreaseDateByOneDecade(date);
    cout << "10- Subtracting One Decade Is : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DecreaseDateByXDecades(date, 10);
    cout << "11- Subtracting 10 Decades Is : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DecreaseDateByOneCentury(date);
    cout << "12- Subtracting One Century Is : " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DecreaseDateByOneMillennium(date);
    cout << "13- Subtracting One Millennium Is : " << date.day << "/" << date.month << "/" << date.year << endl;

    system("pause > nul");
    return 0;
}