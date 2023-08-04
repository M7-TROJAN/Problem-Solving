#include <iostream>
#include <cmath>
using namespace std;

bool CheckPrime(int Number)
{
    int M = round(Number / 2);
    for (int Counter = 2; Counter <= M; Counter++)
    {
        if (Number % Counter == 0)
            return false;
    }
    return true;
}

int RandomNumber(int From, int To)
{
    // Function to generate a random number
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

void AddArrayElement(int Number, int arr[100], int &arrLength)
{
    // its a new element so we need to add the length by 1
    arrLength++;
    arr[arrLength - 1] = Number;
}
void CopyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int &arrDestinationLength)
{
    for (int i = 0; i < arrLength; i++)
        if (CheckPrime(arrSource[i]))
        {
            AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
        }
}
int main()
{
    srand((unsigned)time(NULL));

    int arr[100], arrLength = 0;
    int arr2[100], arr2Length = 0;

    FillArrayWithRandomNumbers(arr, arrLength);

    CopyPrimeNumbers(arr, arr2, arrLength, arr2Length);

    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);
    cout << "\nArray 2 Prime numbers:\n";
    PrintArray(arr2, arr2Length);
    return 0;
}