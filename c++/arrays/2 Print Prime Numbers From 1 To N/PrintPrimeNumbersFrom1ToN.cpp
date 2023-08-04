#include <iostream>
#include <string>
using namespace std;
enum enPrimNotPrime
{
    Prime = 1,
    NotPrime = 2
};
int ReadPositiveNumber(const std::string &message = "")
{
    int number = 0;
    do
    {
        // Display a message to the user asking for a positive integer
        std::cout << message << std::endl;

        // Read an integer value from the user
        std::cin >> number;

        // Check if the input was invalid (i.e. not an integer)
        if (std::cin.fail())
        {
            std::cin.clear();             // Clear the error flag
            std::cin.ignore(10000, '\n'); // Ignore any remaining characters in the input buffer
            std::cout << "Invalid input. Please enter a valid integer." << std::endl;
        }
        // Check if the input was negative or zero
        else if (number <= 0)
        {
            std::cout << "Invalid input. Please enter a positive integer." << std::endl;
        }
    } while (number <= 0);

    // Return the valid positive integer value entered by the user
    return number;
}
enPrimNotPrime CheckPrime(int Number)
{
    int M = round(Number / 2);
    for (int Counter = 2; Counter <= M; Counter++)
    {
        if (Number % Counter == 0)
            return enPrimNotPrime::NotPrime;
    }
    return enPrimNotPrime::Prime;
}
void PrintPrimeNumbersFrom1ToN(int Number)
{
    cout << "\n";
    cout << "Prime Numbers from " << 1 << " To " << Number;
    cout << " are : " << endl;
    for (int i = 1; i <= Number; i++)
    {
        if (CheckPrime(i) == enPrimNotPrime::Prime)
        {
            cout << i << endl;
        }
    }
}

int main()
{
    PrintPrimeNumbersFrom1ToN(ReadPositiveNumber("Please enter a positive number ? ")); 
    return 0;
}