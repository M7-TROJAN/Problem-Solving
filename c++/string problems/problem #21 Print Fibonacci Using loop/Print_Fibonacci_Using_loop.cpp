#include<iostream>
#include <io.h>
#include <fcntl.h>
using namespace std;

// Function to print Fibonacci series using a loop
void PrintFibonacciUsingLoop(short Number)
{
    if (Number > 50)
    {
        _setmode(_fileno(stdout), _O_U16TEXT);
        wcout << L"7araaaaam 3leek El Memory 😡";
        return;
    }

    long long Prev2 = 0, Prev1 = 1;
    long long FebNumber = Prev2 + Prev1;
    
    cout << "Fibonacci Series:\n";
    // Print the first number in the Fibonacci series
    cout << FebNumber << " ";
    
    // Generate and print the remaining Fibonacci numbers
    for (short i = 2; i <= Number; ++i)
    {
        FebNumber = Prev1 + Prev2;
        cout << FebNumber << " ";
        
        // Update the previous two numbers for the next iteration
        Prev2 = Prev1;
        Prev1 = FebNumber;
    }
}

int main()
{
    int n;
    cout << "Enter the number of Fibonacci numbers to print: ";
    cin >> n;
    PrintFibonacciUsingLoop(n);
    return 0;
}
