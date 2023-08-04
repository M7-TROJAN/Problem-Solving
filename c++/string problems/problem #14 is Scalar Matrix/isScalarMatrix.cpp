/*
To check if a matrix is a Scalar matrix, you need to verify the following conditions:

1- The matrix must be square, meaning the number of rows should be equal to the number of columns.
2- All the diagonal elements of the matrix should be have the same value (the scalar value).
3- All the non-diagonal elements should be 0 (zeros).
*/

#include <iostream>
#include <iomanip>
using namespace std;
const int MATRIX_SIZE = 3;  // Change this value according to your matrix size

void fillScalarMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE], int val)
{
    for (int row = 0; row < MATRIX_SIZE ; row++)
    {
        for (int col = 0; col < MATRIX_SIZE; col++)
        {
            matrix[row][col] = (row == col) ? val : 0;
        }
    }
}

void printMatrix(const int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    cout << "Matrix Elements:\n";
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            cout << setw(2) << matrix[i][j] << "   ";
        }
        cout << endl;
    }
}

bool isScalarMatrix(const int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    int scalarValue = matrix[0][0];  // Assume the scalar value is the first element

    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            if (i == j && matrix[i][j] != scalarValue)
            {
                return false;  // Diagonal elements should be equal to the scalar value
            }
            else if (i != j && matrix[i][j] != 0)
            {
                return false;  // Non-diagonal elements should be 0
            }
        }
    }
    return true;  // All conditions are satisfied, it's a scalar matrix
}

int main()
{
    int matrix[MATRIX_SIZE][MATRIX_SIZE];

    fillScalarMatrix(matrix, 9);
    printMatrix(matrix);
    cout << "===========================\n";

    if (isScalarMatrix(matrix))
        cout << "The matrix is a scalar matrix." << endl;
    else
        cout << "The matrix is not a scalar matrix." << endl;
    cout << "===========================\n";

    return 0;
}
