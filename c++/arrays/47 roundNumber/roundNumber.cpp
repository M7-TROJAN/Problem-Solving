#include <iostream>
double get_double(std::string message = "")
{
    double number = 0;
    do
    {
        // Read a double value from the user
        std::cout << message;
        std::cin >> number;

        // Check if the input was invalid (i.e. not an number)
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            // cout << "Invalid input. Please enter a valid number." << endl;
            continue;
        }
        break;
    } while (true);
    return number;
}
// function takes a double number as an argument and rounds it to the nearest integer.
int roundNumber(double num)
{
    /*
    steps:
        1. Add 0.5 to the number.
        2. Cast the result to an integer, which will truncate the decimal part of the number and leave only the integer part.
        3. If the original number was negative, subtract 1 from the rounded value.
    */
    int rounded = (int)(num + 0.5); // Add 0.5 to the number and cast to int
    if (num < 0)
        rounded--; // Subtract 1 if the original number was negative
    return rounded;
}
int main()
{
    double num = get_double("Enter a decimal number to round: ");
    std::cout << "Rounded value of " << num << " is " << roundNumber(num) << std::endl;
    return 0;
}

/*
    number = 10.7
    int part = 10
    fractional Part = 0.7  الجزء العشري
*/

