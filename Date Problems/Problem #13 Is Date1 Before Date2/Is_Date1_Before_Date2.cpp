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

bool IsDate1BeforeDate2(const stDate &date1, const stDate &date2)
{
    if (date1.year < date2.year) return true;
    if (date1.year > date2.year) return false;

    if (date1.month < date2.month) return true;
    if (date1.month > date2.month)return false;

    if (date1.day < date2.day) return true;

    return false;
}

int main()
{
    stDate date1 = readDate();
    std::cout << std::endl;
    stDate date2 = readDate();

    if (IsDate1BeforeDate2(date1, date2))
        std::cout << "\nYes, Date1 is Less than Date2.";
    else
        std::cout << "\nNo, Date1 is NOT Less than Date2.";

    system("pause > nul");
    return 0;
}

// bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
// {
//     return (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ? (Date1.month < Date2.month ? true : (Date1.month == Date2.month ? Date1.day < Date2.day : false)) : false);
// }