#include <iostream>
#include <limits>

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

bool isLeapYear(const short &year)
{
    // A year is a leap year if it is divisible by 4 AND not divisible by 100 OR if it is divisible by 400.
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

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

std::string getDayShortName(const short &dayOfWeekOrder)
{
    const std::string arrDayNames[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return arrDayNames[dayOfWeekOrder];
}

short getNumberOfDaysInAMonth(const short &month, const short &year)
{
    if (month < 1 || month > 12)
        return 0;

    const short NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (month == 2 && isLeapYear(year)) ? 29 : NumberOfDays[month - 1];

    // return (month == 2) ? (isLeapYear(year) ? 29 : 28) : NumberOfDays[month - 1];
}

std::string monthShortName(const short &monthNumber)
{
    std::string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    return (months[monthNumber - 1]);
}

void printMonthCalendar(const short &month, const short &year)
{
    int numberOfDays, currentDay;

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
        if ((currentDay + day) % 7 == 0)
            printf("\n");
    }

    printf("\n_________________________________\n");
}


int main()
{
    short year = getInputInRange(1, INT16_MAX, "Please enter a Year: ");
    short month = getInputInRange(1, 12, "Please enter a Month: ");

    printMonthCalendar(month, year);
    system("pause > nul");
    return 0;
}
