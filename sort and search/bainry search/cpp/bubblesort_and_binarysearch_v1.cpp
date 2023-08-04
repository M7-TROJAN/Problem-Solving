#include <iostream>
using namespace std;

void bubbleSort(string arr[], int n) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < n-1; i++) {
            if (arr[i].compare(arr[i+1]) > 0) {
                string tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                swapped = true;
            }
        }
        n--;
    } while (swapped);
}

int binarySearch(string arr[], int n, string target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;  // Found the target at index mid
        } else if (arr[mid].compare(target) < 0) {
            left = mid + 1;  // Target is in right half of array
        } else {
            right = mid - 1;  // Target is in left half of array
        }
    }
    return -1;  // Target not found in array
}

int main() {
    string arr[] = {"mahmoud", "mohamed", "abdalaziz", "mousa", "mesbah", "mattar", "a", "A", "b", "c", "d", "e", "f", "g", "z", "y", "j", "x"};
    int n = sizeof(arr) / sizeof(arr[0]);
    // Print the array before sorted
    cout << "the array before sort\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " - ";
    }
    cout << endl;
    
    bubbleSort(arr, n);  // Sort the array in ascending order


    cout << "the array after sort\n";
    // Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " - ";
    }
    cout << endl;

    // Prompt user to enter target string to search for
    string target;
    cout << "Enter a string to search for: ";
    cin >> target;

    // Perform binary search on the sorted array to find the target
    int index = binarySearch(arr, n, target);
    if (index == -1) {
        cout << target << " was not found in the array.\n";
    } else {
        cout << target << " was found at index " << index << " in the sorted array.\n";
    }

    return 0;
}