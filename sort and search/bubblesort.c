#include <stdio.h>
#include <stdbool.h>

void bubble_sort(int a[], int length);

int main(void)
{
    int a[] = {1,3,7,0,2,4,9,5,8,6};

    int length = 10;

    bubble_sort(a, length);


    for (int i = 0; i < length; i++)
    printf("a[%d] = %d\n", i, a[i]);

    return 0;
}

void bubble_sort(int a[], int length)
{
    bool swapped = false;
    int i = 0;

    do
    {
    swapped = false;
    for (int j = 0; j < (length - 1 - i); j++)
    {

        if (a[j] > a[j + 1])
        {
            int temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
            swapped = true;
        }
    }
    i++;
    }while (swapped);
}


// ...................................................................


#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int arr[], int length);

int main(void)
{
    int arr[] = {1, 3, 7, 0, 2, 4, 9, 5, 8, 6};
    int length = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, length);

    printf("Sorted array:\n");
    for (int i = 0; i < length; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    return 0;
}

void bubbleSort(int arr[], int length)
{
    bool swapped;
    for (int i = 0; i < length - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < length - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        // If no elements were swapped, the array is already sorted
        if (!swapped)
        {
            break;
        }
    }
}
