#include <iostream>
#include <io.h>
#include <fcntl.h>
using namespace std;

// Function to print Fibonacci series using recursion
void PrintFibonacciUsingRecursion(short Number, short Prev1, short Prev2)
{
    int FebNumber = Prev2 + Prev1;
    if (Number > 0)
    {
        Prev2 = Prev1;
        Prev1 = FebNumber;
        cout << FebNumber << " ";
        PrintFibonacciUsingRecursion(Number - 1, Prev1, Prev2);
    }
}

int main()
{
    int n;
    cout << "Enter the number of Fibonacci numbers to print: ";
    cin >> n;
    PrintFibonacciUsingRecursion(n, 0, 1);
    return 0;
}
