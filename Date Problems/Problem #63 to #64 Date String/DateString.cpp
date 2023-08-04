
#include <iostream>
#include <string>
#include <vector>
struct stDate
{
    short day;
    short month;
    short year;
};

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

bool isValidDate(stDate date)
{
    bool isDayValid = (date.day <= getNumberOfDaysInAMonth(date.month, date.year) && date.day > 0);
    // Ensure the day is less than or equal to the number of days in the given month and year,
    // and greater than 0 to eliminate negative or zero values.

    bool isMonthValid = (date.month <= 12 && date.month > 0);
    // Ensure the month is within the range of valid months, from 1 to 12.

    bool isYearValid = (date.year >= 1);
    // Ensure the year is greater than or equal to 1.

    // Return the overall result of the date validation
    return isDayValid && isMonthValid && isYearValid;
}

// This function splits a string into words using a delimiter
std::vector<std::string> splitString(const std::string &str, const std::string &delimiter = " ")
{
    std::vector<std::string> words;
    std::string currentWord;

    // Iterate through the string to extract and add each word to the vector
    size_t delimiterPos = 0;
    std::string remainingStr = str; // Store the remaining string for manipulation
    while ((delimiterPos = remainingStr.find(delimiter)) != std::string::npos)
    {
        currentWord = remainingStr.substr(0, delimiterPos);
        if (!currentWord.empty())
        {
            words.push_back(currentWord);
        }
        remainingStr.erase(0, delimiterPos + delimiter.length());
    }

    // Add the last word if it exists
    if (!remainingStr.empty())
    {
        words.push_back(remainingStr);
    }

    return words;
}

std::string DateToString(stDate Date)
{
    return std::to_string(Date.day) + "-" + std::to_string(Date.month) + "-" + std::to_string(Date.year);
}

stDate stringToDate(const std::string &dateString)
{
    stDate date;
    std::vector<std::string> vDate;

    vDate = splitString(dateString, "-");

    if (vDate.size() != 3)
        return {0, 0, 0};

    for (std::string element : vDate)
    {
        for (char ch : element)
        {
            if (!isdigit(ch))
                return {0, 0, 0};
        }
    }

    date.day = std::stoi(vDate[0]);
    date.month = std::stoi(vDate[1]);
    date.year = std::stoi(vDate[2]);
    return date;
}

std::string removeSpaces(const std::string &str)
{
    std::string result;

    for (char ch : str)
    {
        if (ch != ' ')
        {
            result += ch;
        }
    }

    return result;
}

std::string readStringDate(const std::string &message = "")
{
    std::string dateString;
    std::cout << message;
    std::getline(std::cin >> std::ws, dateString);
    dateString = removeSpaces(dateString);
    return dateString;
}

stDate readDate(const std::string &message = "Please enter a date in the format (dd-mm-yyyy): ")
{
    stDate date = {0, 0, 0};
    std::string dateString = readStringDate(message);
    date = stringToDate(dateString);

    while (!isValidDate(date))
    {

        std::cout << "Invalid date. Please enter a valid date in the format (dd-mm-yyyy)." << std::endl;
        std::string dateString = readStringDate();
        date = stringToDate(dateString);
    }
    return date;
}

int main()
{

    stDate date = readDate();
    std::cout << "\nDay:" << date.day << std::endl;
    std::cout << "Month:" << date.month << std::endl;
    std::cout << "Year:" << date.year << std::endl;
    std::cout << "\nYou Entered: " << DateToString(date) << "\n";

    system("pause > nul");
    return 0;
}
