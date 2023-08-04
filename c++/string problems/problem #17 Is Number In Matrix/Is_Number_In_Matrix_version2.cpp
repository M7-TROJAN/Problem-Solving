#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MATRIX_ROWS = 6;
const int MATRIX_COLS = 6;

int get_int(const std::string &message = "")
{
    int number = 0;
    do
    {
        // Read an integer value from the user
        std::cout << message;
        std::cin >> number;

        // Check if the input was invalid (i.e. not an integer)
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            // cout << "Invalid input. Please enter a valid integer.\n";
            continue;
        }
        break;
    } while (true);
    return number;
}

void printMatrix(const int matrix[MATRIX_ROWS][MATRIX_COLS])
{
    for (int i = 0; i < MATRIX_ROWS; i++)
    {
        for (int j = 0; j < MATRIX_COLS; j++)
            cout << setw(2) << setfill('0')  << matrix[i][j] << "   ";
        cout << endl;
    }
}

int binarySearch(int matrix[MATRIX_ROWS][MATRIX_COLS], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (matrix[mid / MATRIX_COLS][mid % MATRIX_COLS] == target) {
            return mid; // Found the target at index mid
        } else if (matrix[mid / MATRIX_COLS][mid % MATRIX_COLS] < target) {
            left = mid + 1; // Target is in the right half
        } else {
            right = mid - 1; // Target is in the left half
        }
    }
    return -1; // Target not found
}

int main()
{
    int matrix[MATRIX_ROWS][MATRIX_COLS] = {
        {9, 2, 5, 4, 8, 1},
        {6, 3, 7, 10, -2, 50},
        {20, 0, -1, 12, 14, 77},
        {28, 34, 43, 52, 16, 17},
        {30, 70, 90, 82, 72, 15},
        {61, 99, -6, 13, 79, 41}
    };

    cout << "Matrix Elements Before Sorting:\n";
    printMatrix(matrix);
    cout << "==============================\n";

    // Flatten the 2D matrix to a 1D array to use with std::sort
    int* begin = &matrix[0][0];
    int* end = &matrix[MATRIX_ROWS - 1][MATRIX_COLS - 1] + 1;

    // Sort the elements in the matrix to able to use bainry search algorithm
    sort(begin, end);

    cout << "Matrix Elements After Sorting:\n";
    printMatrix(matrix);
    cout << "==============================\n";

    int target = get_int("Enter A Number To Search For: ");
    int index = binarySearch(matrix, 0, MATRIX_ROWS * MATRIX_COLS - 1, target);

    if (index != -1) {
        int row = index / MATRIX_COLS;
        int col = index % MATRIX_COLS;
        cout << "Number " << target << " found at index (" << row << ", " << col << ").\n";
    }
    else
    {
        cout << "Number " << target << " not found in the matrix.\n";
    }
    return 0;
}