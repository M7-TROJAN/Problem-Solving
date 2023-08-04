#include <iostream>
using namespace std;
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

short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == Number)
            return i; // return the index
    }
    // if you reached here, this means the number is not found
    return -1;
}
bool IsNumberInArray(int Number, int arr[100], int arrLength)
{
    return FindNumberPositionInArray(Number, arr, arrLength) != -1;
}
int main()
{

    srand((unsigned)time(NULL));
    int arr[100], arrLength;
    FillArrayWithRandomNumbers(arr, arrLength);
    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);
    int Number = ReadNumber();
    cout << "\nNumber you are looking for is: " << Number << endl;
    if (!IsNumberInArray(Number, arr, arrLength))
        cout << "No, The number is not found :-(\n";
    else
    {
        cout << "Yes it is found :-)\n";
    }
    return 0;
}