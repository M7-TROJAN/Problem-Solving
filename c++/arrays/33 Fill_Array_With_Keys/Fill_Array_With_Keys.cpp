/*
Problem:
Write a program to read how many keys to generate and fill them in array then print them on the screen.

Input: 
5

Output:
Array elements:
Array[0] : NRXC-DXRO-QEAM-WRWE
Array[1]: BJTR-KIKF-ATEW-WNTT
Array[2]: QOFX-KZEL-SSDP-AKSI
Array[3]: GFOI-ELFX-ZCVE-PSTP
Array(4] : MATF-PRQA-PQEQ-TRIM
*/

#include <iostream>
using namespace std;
enum enCharType {SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4};

int ReadPositiveNumber(const string &message)
{
    int number = 0;
    do
    {
        cout << message << endl;
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

    return number;
}

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

char GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
        case enCharType::SmallLetter:
            return char(RandomNumber(97, 122));
        case enCharType::CapitalLetter:
            return char(RandomNumber(65, 90));
        case enCharType::SpecialCharacter:
            return char(RandomNumber(33, 47));
        case enCharType::Digit:
            return char(RandomNumber(48, 57));
    }
}

void PrintStringArray(string arr[100], int arrLength)
{
    cout << "\nArray elements:\n";
    for (int i = 0; i < arrLength; i++)
    {
        cout << "Index[" << i << "] : ";
        cout << arr[i] << "\n";
    }
    cout << "\n";
}
string GenerateWord(enCharType CharType, short Length)
{
    string Word;
    for (int i = 1; i <= Length; i++)
    {
        Word = Word + GetRandomCharacter(CharType);
    }
    return Word;
}
string GenerateKey()
{
    string Key = "";
    Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4);
    return Key;
}

void FillArrayWithKeys(string arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        arr[i] = GenerateKey();
}

int main()
{

    srand((unsigned)time(NULL));

    string arr[100];
    int arrLength = 0;
    arrLength = ReadPositiveNumber("How many keys do you want to generate?:");
    FillArrayWithKeys(arr, arrLength);
    PrintStringArray(arr, arrLength);
    return 0;
}