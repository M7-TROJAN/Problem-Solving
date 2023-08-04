
// write a program to read how many keys to generate and print them to the screen.

/*
    This program generates a specified number of keys consisting of 16 characters each.
    The user is prompted to enter the number of keys to generate, and the program generates 
    and prints them to the screen.
*/

#include <iostream>
using namespace std;

// This function reads a positive integer from the user and returns it
int ReadPositiveNumber(const string &message)
{
    int number = 0;
    do
    {
        // Display a message to the user asking for a positive integer
        cout << message << endl;

        // Read an integer value from the user
        cin >> number;

        // Check if the input was invalid (i.e. not an integer)
        if (cin.fail())
        {
            cin.clear();             // Clear the error flag
            cin.ignore(10000, '\n'); // Ignore any remaining characters in the input buffer
            cout << "Invalid input. Please enter a valid integer." << endl;
        }
        // Check if the input was negative or zero
        else if (number <= 0)
        {
            cout << "Invalid input. Please enter a positive integer." << endl;
        }
    } while (number <= 0);

    // Return the valid positive integer value entered by the user
    return number;
}

// This function generates a key consisting of 16 characters, including 3 dashes at positions 4, 8, and 12.
string Generate_Key()
{
    int key_length = 16;
    string Key = "";
    for (short i = 1; i <= key_length; i++)
    {
        // Generate a random uppercase letter and append it to the key
        Key += char(rand()%(90 - 65 + 1) + 65);

        // Add a dash after every fourth character, except for the last character
        if (i % 4 == 0 && i > 0 && i != key_length)
            Key += '-';
    }

    return Key;
}

// This function generates and prints the specified number of keys to the screen
void PrintKeys(int NumberOfKeys)
{
    for (short i = 1; i <= NumberOfKeys; i++)
    {
        // Print the key number and the generated key
        cout << "Key[" << i << "]: " << Generate_Key();
        
        cout << endl;
    }
}

int main()
{
    // Prompt the user to enter the number of keys to generate
    int NumberOfKeys = ReadPositiveNumber("Enter NUmber Of Keys: ");

    // Generate and print the specified number of keys to the screen
    PrintKeys(NumberOfKeys);
}
