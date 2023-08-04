
/* 
Problem:
Write a program to fill array with ordered numbers from 1 to N,
then print it,
shuffle this array and print it after shuffle.
*/
#include <iostream>
using namespace std;
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
void Swap(int &A, int &B)
{
    int Temp;
    Temp = A;
    A = B;
    B = Temp;
}
void FillArrayWith1toN(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        arr[i] = i + 1;
}
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
void ShuffleArray(int arr[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
    {
        Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
    }
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
int main()
{
    // Seeds the random number generator
    srand((unsigned)time(NULL));

    int arr[100];
    int arrLength = ReadPositiveNumber("Enter number of elements:");

    FillArrayWith1toN(arr, arrLength);

    cout << "\n========================\n";
    cout << "Array elements before shuffle:\n";
    PrintArray(arr, arrLength);

    ShuffleArray(arr, arrLength);

    cout << "========================\n";
    cout << "Array elements after shuffle:\n";
    PrintArray(arr, arrLength);
    return 0;
}