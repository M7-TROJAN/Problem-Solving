/*
Problem:
Write a program to fill array with max size 100 with random numbers from 1 to 100,
read number and return its index in array if found otherwise return -1
*/

#include <iostream>
using namespace std;
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillArrayWithRandomNumbers(int arr[100], int &arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == Number)
            return i;
    }
    // if you reached here, this means the number is not found
    return -1;
}

int ReadNumber()
{
    int number = 0;
    do
    {
        // Read an integer value from the user
        cout << "Enter a number to search for:\n";
        cin >> number;

        // Check if the input was invalid (i.e. not an integer)
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a valid integer." << endl;
            continue;
        }
        break;
    } while (true);
    return number;
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100], arrLength;

    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\nArray elements:\n";
    PrintArray(arr, arrLength);

    int Number = ReadNumber();
    cout << "\nNumber you are looking for is: " << Number << endl;
    short NumberPosition = FindNumberPositionInArray(Number, arr, arrLength);

    if (NumberPosition == -1)
        cout << "The number is not found :-(\n";
    else
    {
        cout << "The number found at position: ";
        cout << NumberPosition << endl;
        cout << "The number found its order : ";
        cout << NumberPosition + 1 << endl;
    }
    return 0;
}
