#include <iostream>

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

    // Check if the month value is valid
    if (month < 1 || month > 12)
        return 0;

    // Handle February in a leap year
    if (month == 2 && isLeapYear(year))
        return 29;
    else
        return NumberOfDays[month - 1];
}

// Calculates the number of days from the beginning of the year
short getNumberOfDaysFromTheBeginningOfYear(const short &day, const short &month, const short &year)
{
    short totalDays = day;

    // Accumulate the days in each month
    for (int i = 1; i < month; i++)
    {
        totalDays += getNumberOfDaysInAMonth(i, year);
    }

    return totalDays;
}

struct stDate
{
    short day = 0;
    short month = 0;
    short year = 0;
};

stDate dateAddDays(stDate date, const int &daysToAdd)
{
    short remainingDays = daysToAdd + getNumberOfDaysFromTheBeginningOfYear(date.day, date.month, date.year);
    short monthDays = 0;
    date.month = 1;

    // Add the remaining days by iterating over the months
    while (true)
    {
        monthDays = getNumberOfDaysInAMonth(date.month, date.year);

        if (remainingDays > monthDays)
        {
            // Subtract the days of the current month and move to the next month
            remainingDays -= monthDays;
            date.month++;

            if (date.month > 12)
            {
                // Reset month to 1 and increment year if the current month exceeds 12
                date.month = 1;
                date.year++;
            }
        }
        else
        {
            // Assign the remaining days as the day value and break the loop
            date.day = remainingDays;
            break;
        }
    }

    return date;
}

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
int main()
{
    stDate date = readDate();

    int daysToAdd = 0;
    std::cout << "\nHow Many Days To Add?: ";
    std::cin >> daysToAdd;


    // Calculate the updated date by adding the specified number of days
    date = dateAddDays(date, daysToAdd);

    // Output the result
    std::cout << "\nDate after adding [" << daysToAdd << "] days is: ";
    std::cout << date.day << "/" << date.month << "/" << date.year << "\n";

    system("pause > nul");
    return 0;
}
