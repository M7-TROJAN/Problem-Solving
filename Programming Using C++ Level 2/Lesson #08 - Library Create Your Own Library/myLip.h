#include <iostream>
#include <string>
#include <limits>
namespace inputs
{
    int get_int(std::string message = "")
    {
        int number = 0;
        do
        {
            std::cout << message;
            std::cin >> number;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                continue;
            }
            break;
        } while (true);
        return number;
    }

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

    char get_char(std::string message = "")
    {
        char letter = ' ';
        std::cout << message;
        std::cin >> letter;
        return letter;
    }

    std::string get_string(const std::string &message = "")
    {
        std::string str;
        std::cout << message;
        std::getline(std::cin, str);
        return str;
    }
}