#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int *)malloc(num * sizeof(int));
    for (i = 0; i < num; i++)
    {
        scanf("%d", arr + i);
    }

    /* Write the logic to reverse the array. */
    int tmp[num];
    for (int i = 0; i < num; i++)
    {
        tmp[i] = arr[(num - 1) - i];
    }
    arr = tmp;

    for (i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}
