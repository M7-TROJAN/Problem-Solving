/*
write a program to store the multiplication table results 10 x 10 and print them on the screen as shown in the following figure

01 02 03 04 05 06 07 08 09 10 
02 04 06 08 10 12 14 16 18 20 
03 06 09 12 15 18 21 24 27 30
04 08 12 16 20 24 28 32 36 40
05 10 15 20 25 30 35 40 45 50
06 12 18 24 30 36 42 48 54 60
07 14 21 28 35 42 49 56 63 70 
08 16 24 32 40 48 56 64 72 80 
09 18 27 36 45 54 63 72 81 90
10 20 30 40 50 60 70 80 90 100

*/
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    // int x[Rows][Cols];
    int x[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            x[i][j] = (i + 1) * (j + 1);
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%0*d ", 2, x[i][j]);
        }
        cout << endl;
    }
    return 0;
}