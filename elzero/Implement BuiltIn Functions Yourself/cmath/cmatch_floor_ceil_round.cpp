#include <iostream>

float get_float(std::string message = "")
{
    float number = 0;
    do
    {
        // Read a float value from the user
        std::cout << message;
        std::cin >> number;

        // Check if the input was invalid (i.e. not a number)
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

int ceilNumber(double num)
{
    double fractionalPart = num - int(num); // FractionsPart means => (الجزء العشري) الكسور 

    if(fractionalPart <= 0)
        return (int)num;
    else
        return (int)num + 1;
    
    // return (fractionalPart <= 0) ? (int)num : (int)num + 1;
}

int floorNumber(double num)
{
    double fractionalPart = num - int(num); // FractionsPart means => (الجزء العشري) الكسور 
    if(fractionalPart >= 0)
        return (int)num;
    else
        return (int)num - 1;

    // return (fractionalPart >= 0) ? (int)num : (int)num - 1;
}

int main()
{
    float number = get_float("Enter number to round: ");
    std::cout << "Rounded value of " << number << " is " << roundNumber(number) << std::endl;
    std::cout << "Ceiled value of " << number << " is " << ceilNumber(number) << std::endl;
    std::cout << "Floored value of " << number << " is " << floorNumber(number) << std::endl;
}