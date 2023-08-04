#include <iostream>

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

bool IsDate1EqualDate2(const stDate &date1, const stDate &date2)
{
    return date1.year == date2.year && date1.month == date2.month && date1.day == date2.day;
}

int main()
{
    stDate date1 = readDate();
    std::cout << std::endl;
    stDate date2 = readDate();

    if (IsDate1EqualDate2(date1, date2))
        std::cout << "\nYes, Date1 is Equal To Date2.";
    else
        std::cout << "\nNO, Date1 is Not Equal To Date2.";

    system("pause > nul");
    return 0;
}