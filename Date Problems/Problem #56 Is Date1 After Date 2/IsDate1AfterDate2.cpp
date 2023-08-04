#include <iostream>
using namespace std;
struct stDate
{
    short day;
    short month;
    short year;
};

bool IsDate1BeforeDate2(const stDate &date1, const stDate &date2)
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
bool IsDate1EqualDate2(const stDate &date1, const stDate &date2)
{
    return date1.year == date2.year && date1.month == date2.month && date1.day == date2.day;
}

bool IsDate1AfterDate2(const stDate &date1, const stDate &date2) 
{ 
    return (!IsDate1BeforeDate2(date1, date2) &&  !IsDate1EqualDate2(date1, date2));
}

stDate readDate()
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

int main()
{
    stDate date1, date2;

    cout << "Enter Date1:\n";
    date1 = readDate();

    cout << endl;

    cout << "Enter Date2:\n";
    date2 = readDate();

    if(IsDate1AfterDate2(date1, date2))
        cout << "\nYes, Date1 is After Date2."; 
    else
        cout << "\nNo, Date1 is NOT After Date2.";

    system("pause > nul");
    return 0;
}