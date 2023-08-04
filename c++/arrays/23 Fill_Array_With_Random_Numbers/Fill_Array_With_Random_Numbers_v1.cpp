// Write a program to fill array with max size 100 with random numbers from 1 to 100.
#include <iostream>
using namespace std;

int main()
{
    srand(time(NULL));
    int arr[100];

    for (int i = 0; i < size(arr); i++)
    {
        arr[i] = rand() % (100 - 1 + 1) +1;
    }

    for (int i = 0; i < size(arr); i++)
    {
        cout << arr[i] << endl;
    }
    
}