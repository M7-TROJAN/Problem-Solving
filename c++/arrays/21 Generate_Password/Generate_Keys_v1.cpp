
// write a program to read how many keys to generate and print them to the screen.

#include <iostream>
using namespace std;

// An enum to define the different types of characters that can be used in generating the key
enum enCharType
{
    SmallLetter = 1,
    CapitalLetter = 2,
    SpecialCharacter = 3,
    Digit = 4
};

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

// Function to generate a random number within a specified range
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

// Function to get a random character based on the provided character type
char GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
        case enCharType::SmallLetter:
            return char(RandomNumber(97, 122)); // returns a random lowercase letter (ASCII range: 97-122)
        case enCharType::CapitalLetter:
            return char(RandomNumber(65, 90)); // returns a random uppercase letter (ASCII range: 65-90)
        case enCharType::SpecialCharacter:
            return char(RandomNumber(33, 47)); // returns a random special character (ASCII range: 33-47)
        case enCharType::Digit:
            return char(RandomNumber(48, 57)); // returns a random digit (ASCII range: 48-57)
    }
}

// Function to generate a word of a specific character type and length
string GenerateWord(enCharType CharType, short Length)
{
    string Word;
    for (int i = 1; i <= Length; i++)
    {
        Word = Word + GetRandomCharacter(CharType);
    }
    return Word;
}

// Function to generate a key with four groups of 4 random uppercase letters separated by hyphens
string GenerateKey()
{
    string Key = "";

    Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4);

    return Key;
}

// Function to generate and print the requested number of keys to the console
void GenerateKeys(short NumberOfKeys)
{
    for (int i = 1; i <= NumberOfKeys; i++)
    {
        cout << "Key [" << i << "] : ";
        cout << GenerateKey() << endl;
    }
}

int main()
{
    // Seeds the random number generator
    srand((unsigned)time(NULL));
    GenerateKeys(ReadPositiveNumber("Please enter how many keys to generate? \n "));
    return 0;
}