#include <iostream>
#include <limits>
using namespace std;
int ReadNumber(const std::string &message = "")
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
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid integer.\n";
            continue;
        }
        break;
    } while (true);
    return number;
}
int main()
{
    cout << ReadNumber("Please enter a number: ");
}