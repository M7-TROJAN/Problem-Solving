/*
A sparse matrix is a matrix that contains a large number of zero elements compared to the total number of elements.
In other words, it is a matrix where most of the elements have a value of zero.

To check if a matrix is sparse, you need to determine if the number of zero elements in the matrix is greater than a certain threshold.
Typically, a matrix is considered sparse if the number of zero elements exceeds a certain percentage of the total number of elements.
*/
#include <iostream>
#include <iomanip>
using namespace std;

const int MATRIX_ROWS = 3;
const int MATRIX_COLS = 3;

void printMatrix(const int matrix[MATRIX_ROWS][MATRIX_COLS])
{
    for (int i = 0; i < MATRIX_ROWS; i++)
    {
        for (int j = 0; j < MATRIX_COLS; j++)
            cout << setw(2) << matrix[i][j] << "   ";
        cout << endl;
    }
}

bool IsSparseMatrix(int matrix[MATRIX_ROWS][MATRIX_COLS])
{
    int zeroCount = 0, nonZeroCount = 0;
    for (int row = 0; row < MATRIX_ROWS ; row++)
    {
        for (int col = 0; col < MATRIX_COLS; col++)
        {
            if (matrix[row][col] == 0)
                zeroCount++;
            else
                nonZeroCount++;
            // (matrix[row][col] == 0) ? zeroCount++ : nonZeroCount++;
        }
    }
    return zeroCount > nonZeroCount;
}

int main()
{
    int matrix[MATRIX_ROWS][MATRIX_COLS] = {
        {1, 0, 0},
        {0, 2, 0},
        {0, 0, 3}
    };

    cout << "Matrix Elements:\n";
    printMatrix(matrix);
    cout << "==============================\n";

    if (IsSparseMatrix(matrix))
        cout << "The matrix is a sparse matrix." << endl;
    else
        cout << "The matrix is not a sparse matrix." << endl;
    cout << "==============================\n";

    cin.get();
    return 0;
}
