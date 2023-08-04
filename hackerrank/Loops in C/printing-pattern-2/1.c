#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    /*
    7 7 7 7 7 7 7 7 7 7 7 7 7
    7 6 6 6 6 6 6 6 6 6 6 6 7
    7 6 5 5 5 5 5 5 5 5 5 6 7
    7 6 5 4 4 4 4 4 4 4 5 6 7
    7 6 5 4 3 3 3 3 3 4 5 6 7
    7 6 5 4 3 2 2 2 3 4 5 6 7
    7 6 5 4 3 2 1 2 3 4 5 6 7
    7 6 5 4 3 2 2 2 3 4 5 6 7
    7 6 5 4 3 3 3 3 3 4 5 6 7
    7 6 5 4 4 4 4 4 4 4 5 6 7
    7 6 5 5 5 5 5 5 5 5 5 6 7
    7 6 6 6 6 6 6 6 6 6 6 6 7
    7 7 7 7 7 7 7 7 7 7 7 7 7
    */

    int n;
    scanf("%d", &n);
    // Complete the code to print the pattern.

    int size = 2 * n - 1;
    int start = 0;
    int end = size - 1;
    int arr[size][size];

    while (n != 0)
    {
        for (int i = start; i <= end; i++)
        {
            for (int j = start; j <= end; j++)
            {
                if (i == start || i == end || j == start || j == end)
                    arr[i][j] = n;
            }
        }
        ++start;
        --end;
        --n;
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
