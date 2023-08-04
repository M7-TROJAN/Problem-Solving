/*
Program: Convert Numbers To Text
This code was written by Mahmoud Mohamed (mahmoud.abdalaziz@outlook.com)

Note: The program is limited to handling numbers 2,147,483,647 (the maximum value for a signed 32-bit integer).
*/

#include <iostream>
#include <string>
#include <limits>
using namespace std;

int get_integer(const std::string &message = "")
{
    int number = 0;
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
            // cout << "Invalid input. Please enter a valid integer.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        break;
    } while (true);
    return number;
}

string NumberToText(const int &Number)
{
    if (Number == 0)
    {
        return "";
    }

    if (Number >= 1 && Number <= 19)
    {
        string arr[] = 
        {
            "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
            "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
        };
        return arr[Number] + " ";
    }

    if (Number >= 20 && Number <= 99)
    {
        string arr[] = {
            "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        return arr[Number / 10] + " " + NumberToText(Number % 10);
    }
    
    if (Number >= 100 && Number <= 999)
    {
        return NumberToText(Number / 100) + "Hundred " + NumberToText(Number % 100);
    }

    if (Number >= 1000 && Number <= 1999)
    {
        return "One Thousand " + NumberToText(Number % 1000);
    }

    if (Number >= 2000 && Number <= 999999)
    {
        return NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
    }

    if (Number >= 1000000 && Number <= 1999999)
    {
        return "One Million " + NumberToText(Number % 1000000);
    }
    if (Number >= 2000000 && Number <= 999999999)
    {
        return NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
    }

    if (Number >= 1000000000 && Number <= 1999999999)
    {
        return "One Billion " + NumberToText(Number % 1000000000);
    }
    if(Number >= 1000000000 && Number <= 2147483647)
    {
        return NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
    }

    else
    {
        return "Out Of Range.";
    }
}

int main()
{
    int Number = get_integer("Enter a Number: ");
    cout << NumberToText(Number);
    system("pause > nul");
    return 0;
}

// Note: The program has a limitation It's only supports numbers up to 2,147,483,647 (the maximum value for a signed 32-bit integer).

