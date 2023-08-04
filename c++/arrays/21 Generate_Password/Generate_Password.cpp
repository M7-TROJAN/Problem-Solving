#include <iostream>
#include <random> // for random_device, mt19937, uniform_int_distribution
using namespace std;

// This function reads a positive integer from the user and returns it
int ReadPositiveNumber(const string &message)
{
    int number = 0;
    while (true)
    {
        // Display a message to the user asking for a positive integer
        cout << message;

        // Read an integer value from the user
        if (!(cin >> number))
        {
            // If input was invalid, clear the error flag and ignore any remaining characters in the input buffer
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid integer." << endl;
        }
        else if (number <= 0)
        {
            cout << "Invalid input. Please enter a positive integer." << endl;
        }
        else
        {
            // Input is valid, break out of the loop and return the value
            break;
        }
    }

    return number;
}

void GeneratePassword()
{
    const int PASSWORD_LENGTH = 16;
    const string CHARACTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=";
    random_device rd; // creates a random_device object to obtain a seed for the random number generator
    mt19937 gen(rd()); // creates a mersenne_twister_engine seeded with the random_device object
    uniform_int_distribution<> dis(0, CHARACTERS.length() - 1); // creates a uniform integer distribution object for generating random numbers between 0 and the length of the character set - 1

    string password = "";
    for (int i = 0; i < PASSWORD_LENGTH; i++)
    {
        if (i % 4 == 0 && i > 0)
        {
            password += '-';
        }
        password += CHARACTERS[dis(gen)]; // generate a random character from the character set
    }

    cout << password << endl;
}

int main()
{
    int numberOfKeys = ReadPositiveNumber("Enter number of keys: ");

    for (int i = 1; i <= numberOfKeys; i++)
    {
        cout << "Password[" << i << "]: ";
        GeneratePassword();
    }

    return 0;
}
