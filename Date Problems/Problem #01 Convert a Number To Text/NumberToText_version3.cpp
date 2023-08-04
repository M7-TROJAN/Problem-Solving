/*
Program: Convert Numbers To Text
This code was written by Mahmoud Mohamed (mahmoud.abdalaziz@outlook.com)

Note: The program is limited to handling numbers up to 9,999,999,999,999 (9.9 trillion),
which is the maximum value supported by the 64-bit integer type (long long).
*/

#include <iostream>
#include <string>
#include <limits>

// Function to convert a number to its textual representation
std::string convertNumberToText(const long long& number);
std::string NumberToText(const long long& number);

// Function to get a long long integer from the user
long long GetLongLongInt(const std::string& message = "");

int main()
{
    long long number = GetLongLongInt("Enter a number: ");
    std::cout << convertNumberToText(number) << std::endl;
    std::cin.get();
    return 0;
}

// Function to convert a number to its textual representation
std::string convertNumberToText(const long long& number)
{
    std::string text = NumberToText(number);
    if(text.empty())
        return "Zero";
    return text;
}

// Function to convert a number to its textual representation
std::string NumberToText(const long long& number)
{
    // Check if the number is zero
    if (number == 0)
    {
        return "";
    }

    // Check if the number is negative
    if (number < 0)
    {
        return "Negative " + NumberToText(-number);
    }

    // Handle numbers from 1 to 19
    if (number >= 1 && number <= 19)
    {
        std::string unitsText[] =
        {
            "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
            "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
        };
        return unitsText[number] + " ";
    }

    // Handle numbers from 20 to 99
    if (number >= 20 && number <= 99)
    {
        std::string tensText[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        return tensText[number / 10] + " " + NumberToText(number % 10);
    }

    // Handle numbers from 100 to 999
    if (number >= 100 && number <= 999)
    {
        return NumberToText(number / 100) + "Hundred " + NumberToText(number % 100);
    }

    // Handle numbers from 1000 to 1999
    if (number >= 1000 && number <= 1999)
    {
        return "One Thousand " + NumberToText(number % 1000);
    }
    // Handle numbers from 2000 to 999,999
    if (number >= 2000 && number <= 999999)
    {
        return NumberToText(number / 1000) + "Thousands " + NumberToText(number % 1000);
    }

    // Handle numbers from 1,000,000 to 1,999,999
    if (number >= 1000000 && number <= 1999999)
    {
        return "One Million " + NumberToText(number % 1000000);
    }
    // Handle numbers from 2,000,000 to 999,999,999
    if (number >= 2000000 && number <= 999999999)
    {
        return NumberToText(number / 1000000) + "Millions " + NumberToText(number % 1000000);
    }

    // Handle numbers from 1,000,000,000 to 1,999,999,999
    if (number >= 1000000000 && number <= 1999999999)
    {
        return "One Billion " + NumberToText(number % 1000000000);
    }
    // Handle numbers from 2,000,000,000 to 999,999,999,999
    if (number >= 2000000000 && number <= 999999999999)
    {
        return NumberToText(number / 1000000000) + "Billions " + NumberToText(number % 1000000000);
    }

    // Handle numbers from 1,000,000,000,000 to 1,999,999,999,999  "I Can't Read these Numbers :")😂"
    if (number >= 1000000000000 && number <= 1999999999999)
    {
        return "One Trillion " + NumberToText(number % 1000000000000);
    }
    else
    {
        return NumberToText(number / 1000000000000) + "Trillions " + NumberToText(number % 1000000000000);
    }
}

long long GetLongLongInt(const std::string& message)
{
    long long number = 0;
    do
    {
        std::cout << message;
        std::cin >> number;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        break;
    } while (true);
    return number;
}
