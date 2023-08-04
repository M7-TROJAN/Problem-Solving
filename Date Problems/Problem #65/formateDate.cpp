
#include <iostream>
#include <string>
struct stDate
{
    short day;
    short month;
    short year;
};

// Reads a date from the user by separately requesting the day, month, and year.
// Returns a stDate structure representing the entered date.
stDate readDateOldVersion()
{
    stDate date;
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

// Replaces all occurrences of a word in a string with a specified replacement.
// Returns the modified string.
std::string replaceWordInString(const std::string &input, const std::string &wordToReplace, const std::string &replacement)
{
    std::string result = input;
    size_t pos = 0;
    while ((pos = result.find(wordToReplace, pos)) != std::string::npos)
    {
        result.replace(pos, wordToReplace.length(), replacement);
        pos += replacement.length(); // Move past the replaced word
    }
    return result;
}

// Formats a date structure according to the provided date format.
// Returns a string representing the formatted date.
std::string formateDate(const stDate &date, const std::string &dateFormat = "dd-mm-yyyy")
{
    std::string formattedDateString = "";
    formattedDateString = replaceWordInString(dateFormat, "dd", std::to_string(date.day));
    formattedDateString = replaceWordInString(formattedDateString, "mm", std::to_string(date.month));
    formattedDateString = replaceWordInString(formattedDateString, "yyyy", std::to_string(date.year));
    return formattedDateString;
}

int main()
{

    stDate Date = readDateOldVersion();
    std::cout << "\n" << formateDate(Date) << "\n";
    std::cout << "\n" << formateDate(Date, "dd/mm/yyyy") << "\n";
    std::cout << "\n" << formateDate(Date, "yyyy/dd/mm") << "\n";
    std::cout << "\n" << formateDate(Date, "mm/dd/yyyy") << "\n";
    std::cout << "\n" << formateDate(Date, "mm-dd-yyyy") << "\n";
    std::cout << "\n" << formateDate(Date, "dd mm yyyy") << "\n";
    std::cout << "\n" << formateDate(Date, "Day:dd, Month:mm, Year:yyyy") << "\n";
    system("pause > nul");
}