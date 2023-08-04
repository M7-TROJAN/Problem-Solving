#include <iostream>
#include <string>
#include <sstream>
#include <limits>
using namespace std;
struct stDate
{
    short day;
    short month;
    short year;
};

struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
};

enum enDateCompare
{
    Before = -1,
    Equal = 0,
    After = 1
};

// Determines if the given year is a leap year
// Leap year if year is divisible by 4 AND not divisible by 100 OR if it's divisible by 400
bool isLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

// Returns the number of days in a specific month of a year
short getNumberOfDaysInAMonth(const short& month, const short& year)
{
    if (month < 1 || month > 12) return 0;

    const short NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    return (month == 2 && isLeapYear(year)) ? 29 : NumberOfDays[month - 1];
}

bool IsDate1BeforeDate2(const stDate& date1, const stDate& date2)
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

// Checks if date1 is Equal to date2
bool IsDate1EqualDate2(const stDate& date1, const stDate& date2)
{
    return date1.year == date2.year && date1.month == date2.month && date1.day == date2.day;
}

bool IsDate1AfterDate2(const stDate& date1, const stDate& date2)
{
    return (!IsDate1BeforeDate2(date1, date2) && !IsDate1EqualDate2(date1, date2));
}

// compDates function compares two dates and returns an enDateCompare value based on the comparison.
// If date1 is before date2, it returns enDateCompare::Before.  -1
// If date1 is equal to date2, it returns enDateCompare::Equal.  0
// If date1 is after date2, it returns enDateCompare::After.     1
enDateCompare compDates(stDate date1, stDate date2)
{
    if (IsDate1EqualDate2(date1, date2))
        return enDateCompare::Equal;
    if (IsDate1AfterDate2(date1, date2))
        return enDateCompare::After;
    return enDateCompare::Before;
}

stDate readFullDate()
{
    stDate date;
    std::string inputDate;

    // Get the input from the user
    std::cout << "Please enter a date in the format (dd-mm-yyyy): ";
    std::getline(std::cin, inputDate);

    // Remove any non-digit characters from the input
    inputDate.erase(std::remove_if(inputDate.begin(), inputDate.end(), [](char c) { return !std::isdigit(c); }), inputDate.end());

    // Validate the input length
    if (inputDate.length() != 8)
    {
        std::cout << "Invalid date format. Please enter a valid date in the format (dd-mm-yyyy)." << std::endl;
        return readFullDate();
    }

    // Extract day, month, and year from the input string
    try {
        date.day = std::stoi(inputDate.substr(0, 2));
        date.month = std::stoi(inputDate.substr(2, 2));
        date.year = std::stoi(inputDate.substr(4, 4));
    }
    catch (std::invalid_argument& e) {
        std::cout << "Invalid date format. Please enter a valid date in the format (dd-mm-yyyy)." << std::endl;
        return readFullDate();
    }

    // Validate the entered date
    if (date.day < 1 || date.day > 31 || date.month < 1 || date.month > 12 || date.year < 1 || date.day > getNumberOfDaysInAMonth(date.month, date.year))
    {
        std::cout << "Invalid date. Please enter a valid date in the format (dd-mm-yyyy)." << std::endl;
        return readFullDate();
    }

    return date;
}

stPeriod ReadPeriod()
{
    stPeriod Period;
    cout << "\nEnter Start Date:\n";
    Period.StartDate = readFullDate();
    cout << "\nEnter End Date:\n";
    Period.EndDate = readFullDate();
    return Period;
}

// Function to check if two periods overlap
bool isOverlapPeriods(stPeriod period1, stPeriod period2)
{
    if (compDates(period2.EndDate, period1.StartDate) == enDateCompare::Before ||
        compDates(period2.StartDate, period1.EndDate) == enDateCompare::After)
        return false;
    return true;
}


int main()
{

    cout << "\nEnter Period 1";
    stPeriod period1 = ReadPeriod();

    cout << "\nEnter Period 2";
    stPeriod period2 = ReadPeriod();

    if (isOverlapPeriods(period1, period2))
        cout << "\nYes, Periods Overlap\n";
    else
        cout << "\nNo, Periods Don't Overlap\n";

    system("pause > nul");
    

    return 0;
}



// bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2) {

// 	return IsDate1BeforeDate2(Period2.StartDate,Period1.EndDate) || IsDate1EqualDate2(Period1.EndDate,Period2.StartDate);
// }
