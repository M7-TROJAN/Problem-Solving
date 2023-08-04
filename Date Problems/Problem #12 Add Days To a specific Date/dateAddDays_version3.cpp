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
    if (month < 1 || month > 12) return 0;

    const short NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (month == 2 && isLeapYear(year))? 29 : NumberOfDays[month - 1];
}

struct stDate
{
    short day = 0;
    short month = 0;
    short year = 0;
};

stDate dateAddDays(const stDate &curentDate, const int &daysToAdd)
{
    stDate newDate;
    newDate.year = curentDate.year;
    int totalDays = 0;

    int day = curentDate.day+1;
    for (short month = curentDate.month; month <= 12; month++)
    {
        int daysInMonth = getNumberOfDaysInAMonth(month, newDate.year);
        for (day; day <= daysInMonth; day++)
        {
            totalDays++;
            if (totalDays == daysToAdd)
            {
                newDate.day = day;
                newDate.month = month;
                return newDate;
            }
        }
        day = 1;
        if(month == 12)
        {
            month = 0; // It will be incremented to 1 in the next iteration
            newDate.year++;
        }
    }

    return newDate;
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
}
int main()
{
    stDate date = readDate();

    int daysToAdd = 0;
    std::cout << "\nEnter the number of days to add: ";
    std::cin >> daysToAdd;
    // Note: You must verify that the user's input is correct.
    // For example, ensure the user does not enter a day less than 1 or greater than 31,
    // and that the user does not enter a month less than 1 or greater than 12.


    // Calculate the updated date by adding the specified number of days
    date = dateAddDays(date, daysToAdd);

    // Output the result
    std::cout << "\nDate after adding [" << daysToAdd << "] days is: ";
    std::cout << date.day << "/" << date.month << "/" << date.year << "\n";

    system("pause > nul");
    return 0;
}
