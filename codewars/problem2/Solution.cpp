#include <iostream>
#include <vector>
// This function reads a non negative integer from the user and returns it
int ReadPositiveNumber(const std::string &message = "")
{
    int number = 0;
    do
    {
        // Display a message to the user asking for a positive integer
        std::cout << message;

        // Read an integer value from the user
        std::cin >> number;

        // Check if the input was invalid (i.e. not an integer)
        if (std::cin.fail())
        {
            std::cin.clear();             // Clear the error flag
            std::cin.ignore(100000, '\n'); // Ignore any remaining characters in the input buffer
            std::cout << "Invalid input. Please enter a valid integer." << std::endl;
        }
        // Check if the input was negative
        else if (number <= 0)
        {
            std::cout << "Invalid input. Please enter a positive integer." << std::endl;
        }
    } while (number <= 0);

    // Return the valid positive integer value entered by the user
    return number;
}

int get_int(const std::string &message = "")
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
            std::cin.ignore(10000, '\n');
            continue;
        }
        break;
    } while (true);
    return number;
}

void addElementsToVector(std::vector<int> &vNumbers , int size)
{
    char ReadMore = 'Y';
    do
    {
        for(int i = 0 ; i < size ; i++)
        {
            vNumbers.push_back(get_int("Enter A Number: "));
        }
        std::cout << "Do You Want To Add More?: ";
        std::cin  >> ReadMore;
    } while (ReadMore == 'y' || ReadMore == 'Y');
}

void PrintVectorElements(std::vector<int> &vNumbers)
{
    std::cout << "\nNumbers Vector:\n";
    for (int &number : vNumbers)
        std::cout << number << " ";
    std::cout << std::endl;
}
int main()
{
    std::vector<int> vNumbers;
    int vSize = ReadPositiveNumber("How Many Elements Will You Add?: ");
    addElementsToVector(vNumbers, vSize);
    PrintVectorElements(vNumbers);
}