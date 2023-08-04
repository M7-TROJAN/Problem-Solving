#include <iostream>
#include <limits>
#include <ctime>

// Reads an integer value from the user between the given range and returns it
int getInputInRange(const int &from, const int &to, const std::string &message = "")
{
    float number = 0;
    do
    {
        // Read an integer value from the user
        std::cout << message;
        std::cin >> number;

        // Check if the input was invalid (i.e. not an integer)
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid integer between " << from << " to " << to << std::endl;
            continue;
        }
        if (number < from || number > to)
        {
            std::cout << "Please enter a number between " << from << " to " << to << std::endl;
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        break;
    } while (true);
    return number;
}

// Checks if a year is a leap year
bool isLeapYear(const short &year)
{
    // A year is a leap year if it is divisible by 4 AND not divisible by 100 OR if it is divisible by 400.
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Calculates the day of the week (0: Sun, 1: Mon, 2: Tue, ..., 6: Sat) for a given date
short calculateDayOfWeekOrder(const short &day, const short &month, const short &year)
{
    short a, y, m;

    a = (14 - month) / 12;
    y = year - a;
    m = month + (12 * a) - 2;

    // Calculate the day of the week using Gregorian Calendar formula
    // Gregorian (ميلادي) => 0: Sun, 1: Mon, 2: Tue, ... , 6: Sat
    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

// Retrieves the short name of the day of the week based on its order
std::string getDayShortName(const short &dayOfWeekOrder)
{
    const std::string arrDayNames[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return arrDayNames[dayOfWeekOrder];
}

// Retrieves the number of days in a given month of a year
short getNumberOfDaysInAMonth(const short &month, const short &year)
{
    if (month < 1 || month > 12)
        return 0;

    const short NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (month == 2 && isLeapYear(year)) ? 29 : NumberOfDays[month - 1];
}

// Retrieves the short name of a month based on its number
std::string monthShortName(const short &monthNumber)
{
    std::string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    return (months[monthNumber - 1]);
}

// Prints the calendar for a given month and year
void printMonthCalendar(const short &month, const short &year)
{
    int currentDay, numberOfDays;

    // Get the index of the day from 0 to 6
    currentDay = calculateDayOfWeekOrder(1, month, year);

    numberOfDays = getNumberOfDaysInAMonth(month, year);

    // Print the current month name
    printf("\n_____________ %s _______________\n\n", monthShortName(month).c_str());
    // Print the columns
    printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    // Print appropriate spaces for the first day
    for (int i = 0; i < currentDay; i++)
        printf("     ");

    // Print days with proper alignment
    for (int day = 1; day <= numberOfDays; day++)
    {
        printf("%-5d", day);
        if ((currentDay + day) % 7 == 0) // just some Logic Bro :)
            printf("\n");
    }

    printf("\n__________________________________\n");
}

// Prints the calendar for a given year
void printYearCalendar(const short &year)
{
    printf("\n_________________________________\n\n");
    printf("        Calender - %hd        ", year);
    printf("\n_________________________________\n\n");
    for(int month = 1; month <= 12; month++)
    {
        printMonthCalendar(month, year);
    }
}


int main()
{
    time_t Time = time(NULL);
    tm Now;
    localtime_s(&Now, &Time);
    short currentYear = Now.tm_year + 1900;

    short year = getInputInRange(1900, currentYear + 15, "Please enter a Year: ");

    system("cls");
    printYearCalendar(year);
    system("pause > nul");
    return 0;
}