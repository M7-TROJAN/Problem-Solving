#include <iostream>
#include <string>
#include <algorithm> // for std::sort()
using namespace std;

// Sorts the array in ascending order using the bubble sort algorithm
void bubbleSort(string arr[], int n) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) { // if current element is greater than next element
                swap(arr[i], arr[i + 1]); // swap elements
                swapped = true;
            }
        }
        n--;
    } while (swapped);
}

// Searches for target string in the sorted array using binary search
int binarySearch(string arr[], int n, string target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) { // if middle element is the target
            return mid; // return its index
        } else if (arr[mid] < target) { // if target is greater than middle element
            left = mid + 1; // target must be in right half of array
        } else { // if target is less than middle element
            right = mid - 1; // target must be in left half of array
        }
    }
    return -1; // target not found in array
}

int main() {
    string arr[] = {"mahmoud", "mohamed", "abdalaziz", "mousa", "mesbah", "mattar", "a", "A", "b", "c", "d", "e", "f", "g", "z", "y", "j", "x"};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print the array before sorting
    cout << "Array before sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " - ";
    }
    cout << endl;

    bubbleSort(arr, n); // sort the array in ascending order

    // Print the sorted array
    cout << "Array after sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " - ";
    }
    cout << endl;

    // Prompt user to enter target string to search for
    string target;
    cout << "Enter a string to search for: ";
    cin >> target;

    // Search for target in the sorted array using binary search
    int index = binarySearch(arr, n, target);
    if (index == -1) {
        cout << target << " was not found in the array." << endl;
    } else {
        cout << target << " was found at index " << index << " in the sorted array." << endl;
    }

    return 0;
}
