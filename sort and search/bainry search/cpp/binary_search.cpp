#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[] , int n)
{
    bool swapped;
    do
    {
        swapped = false;
        for (size_t i = 0; i < n-1; i++)
        {
            if (arr[i] > arr[i+1])
            {
                int tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                swapped = true;
            }
        }
        n--;
    } while (swapped);
}
int bainrysearch(int arr[] , int n , int target)
{
    int left = 0 , right = n-1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if(target == arr[mid])
            return mid;
        else if(target < arr[mid])
            right = mid-1;
        else if (target > arr[mid])
            left = mid+1;
    }
    return -1;
}
int main() {
    int arr[] = {10,2,70,90,60,87,563,40,12,50,98,710,3,20,30,45,100};
    // get length of the array
    int n = sizeof (arr)/ sizeof(arr[0]);
    // sort the array
    bubbleSort(arr, n);
    int target;
    // get the target from user
    cout << "search for: ";
    cin >> target;

    // use bainry search algorithm to search if the target into the array ar not
    int result = bainrysearch(arr, n , target);
    // check if result == -1 then target is not found else target is in index result
    if (result == -1)
        cout << target << " is not Found\n";
    else
        cout << target << " is found in index " << result << endl;
}
