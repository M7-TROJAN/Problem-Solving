#include <iostream>
#include <cstdio>

short calculateDayOfWeekOrder(short day, short month, short year)
{
    short a, y, m;

    a = (14 - month) / 12;
    y = year - a;
    m = month + (12 * a) - 2;

    // Calculate the day of the week using Gregorian Calendar formula
    // Gregorian (ميلادي) => 0: Sun, 1: Mon, 2: Tue, ... , 6: Sat
    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

std::string getDayShortName(short dayOfWeekOrder)
{
    const std::string arrDayNames[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return arrDayNames[dayOfWeekOrder];
}

int main()
{
    short year, month, day;

    std::cout << "Please enter a date in the format (d/m/y): ";
    std::scanf("%hd%*c%hd%*c%hd", &day, &month, &year);

    std::cout << "\nDate      : " << day << "/" << month << "/" << year;
    std::cout << "\nDay Order : " << calculateDayOfWeekOrder(day, month, year);
    std::cout << "\nDay Name  : " << getDayShortName(calculateDayOfWeekOrder(day, month, year));

    system("pause > nul");
    return 0;
}

