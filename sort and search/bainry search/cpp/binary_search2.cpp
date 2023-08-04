#include <bits/stdc++.h>
using namespace std;

// Function to sort an integer array using bubble sort algorithm
void bubbleSort(int arr[], int n) {
    bool swapped; // flag to track if any swaps were made during an iteration
    do {
        swapped = false; // initialize the flag to false
        for (size_t i = 0; i < n-1; i++) {
            if (arr[i] > arr[i+1]) { // if two adjacent elements are out of order
                int tmp = arr[i]; // swap the elements
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                swapped = true; // set the flag to true
            }
        }
        n--; // decrement the size of the unsorted portion of the array
    } while (swapped); // continue iterating until no swaps are made
}

// Function to search for a target value in a sorted integer array using binary search algorithm
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n-1; // initialize the left and right endpoints of the search range
    while (left <= right) { // continue searching until the search range is empty
        int mid = left + (right - left) / 2; // calculate the index of the middle element
        if (target == arr[mid]) // if the target value is equal to the middle element
            return mid; // return the index of the middle element
        else if (target < arr[mid]) // if the target value is less than the middle element
            right = mid-1; // search the left half of the search range
        else if (target > arr[mid]) // if the target value is greater than the middle element
            left = mid+1; // search the right half of the search range
    }
    return -1; // return -1 if the target value is not found
}

int main() {
    int arr[] = {10, 2, 70, 90, 60, 87, 563, 40, 12, 50, 98, 710, 3, 20, 30, 45, 100}; // initialize an integer array
    int n = sizeof(arr) / sizeof(arr[0]); // calculate the length of the array
    bubbleSort(arr, n); // sort the array using bubble sort
    int target; // initialize a variable to hold the target value to search for
    cout << "Search for: ";
    cin >> target; // prompt the user to input the target value
    int result = binarySearch(arr, n, target); // search for the target value in the sorted array
    if (result == -1)
        cout << target << " is not found." << endl; // display a message indicating that the target value was not found
    else
        cout << target << " is found at index " << result << "." << endl; // display the index of the target value in the array
    return 0;
}
