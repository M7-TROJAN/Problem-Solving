#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>

using namespace std;

const int MATRIX_ROWS = 3;
const int MATRIX_COLS = 3;

void printMatrix(const int matrix[MATRIX_ROWS][MATRIX_COLS])
{
    for (int i = 0; i < MATRIX_ROWS; i++)
    {
        for (int j = 0; j < MATRIX_COLS; j++)
        {
            cout << setw(2) << setfill('0') << matrix[i][j] << "   ";
        }
        cout << endl;
    }
}

bool isPalindromeMatrix(const int matrix[MATRIX_ROWS][MATRIX_COLS])
{
    for (int row = 0; row < MATRIX_ROWS; row++)
    {
        for (int col = 0; col < MATRIX_COLS / 2; col++)
        {
            if (matrix[row][col] != matrix[row][MATRIX_COLS - 1 - col])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int matrix[MATRIX_ROWS][MATRIX_COLS] = {{1, 2, 1}, {5, 5, 5}, {7, 3, 7}};
    cout << "Matrix Elements:\n";
    printMatrix(matrix);
    cout << "===========================\n";

    if (isPalindromeMatrix(matrix))
    {
        cout << "Yes: Matrix is a Palindrome\n";
    }
    else
    {
        cout << "No: Matrix is NOT a Palindrome\n";
    }

    return 0;
}
