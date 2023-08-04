#include <iostream>
#include <cmath>
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
double square_root(double num) {
    if (num < 0) {
        return -1;
    }
    return pow(num, 0.5);
}

int main() {
    double num = get_double("Enter a number to calculate its square root: ");
    // Handle negative numbers
    if (num < 0)
        std::cerr << "Cannot calculate square root of a negative number\n";
    else
        std::cout << "The square root of " << num << " is " << square_root(num) << "\n";
    return 0;
}
