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
    std::cout << "Floored value of " << number << " is " << floorNumber(number) << std::endl;
    /* 
    Note: 
        0 is not positive or negative number then if the user input -0  floorNumber() will return 0 not -1
    */
}