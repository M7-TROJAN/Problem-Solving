
#include <iostream>
#include <tuple>

// Checks if a year is a leap year
bool isLeapYear(const short &year)
{
    // A year is a leap year if it is divisible by 4 AND not divisible by 100 OR if it is divisible by 400.
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
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

// Retrieves the date (day, month, year) from the given day order in the year
std::tuple<short, short, short> GetDateFromDayOrderInYear(const short &daysOrderInYear, const short &year)
{
    short day = 0, month = 0, yearResult = 0;

    int totalDays = 0;
    for (int currentMonth = 1; currentMonth <= 12; currentMonth++)
    {
        int daysInMonth = getNumberOfDaysInAMonth(currentMonth, year);
        for (int currentDay = 1; currentDay <= daysInMonth; currentDay++)
        {
            totalDays++;
            if (totalDays == daysOrderInYear)
            {
                day = currentDay;
                month = currentMonth;
                yearResult = year;
                return std::make_tuple(day, month, yearResult);
            }
        }
    }

    // If the daysOrderInYear is invalid, return a default invalid date
    return std::make_tuple(day, month, yearResult);
}


// Note: It is important to validate the user's input to ensure they do not enter invalid values for day, month, or year.
// While this code does not include input validation to keep it concise,
// it is strongly recommended to add appropriate checks to ensure the input is valid.
// Consider implementing checks to ensure the day is within the range of 1-31, the month is within the range of 1-12,
// and the year is within a reasonable range.
int main()
{
    short day, month, year;
    std::cout << "Please enter a Day: ";
    std::cin >> day;
    std::cout << "Please enter a Month: ";
    std::cin >> month;
    std::cout << "Please enter a Year: ";
    std::cin >> year;

    short daysOrderInYear = getNumberOfDaysFromTheBeginningOfYear(day, month, year);
    std::cout << "\nNumber of days from the beginning of the year: " << daysOrderInYear << std::endl;

    std::tuple<short, short, short> date = GetDateFromDayOrderInYear(daysOrderInYear, year);

    std::cout << "\nDate for [" << daysOrderInYear << "] is: ";
    std::cout << std::get<0>(date) << "/" << std::get<1>(date) << "/" << std::get<2>(date);

    system("pause > nul");
    return 0;
}