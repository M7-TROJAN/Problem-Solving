/*
To check if a matrix is an identity matrix, you need to verify the following conditions:

1- The matrix must be square, meaning the number of rows should be equal to the number of columns.
2- All the diagonal elements of the matrix should be 1 (ones).
3- All the non-diagonal elements should be 0 (zeros).
*/

#include <iostream>
#include <iomanip>
using namespace std;
const int MATRIX_SIZE = 3;  // Change this value according to your matrix size

void fillIdentityMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    for (int row = 0; row < MATRIX_SIZE ; row++)
    {
        for (int col = 0; col < MATRIX_SIZE; col++)
        {
            matrix[row][col] = (row == col) ? 1 : 0;
            
            // if(row == col)
            //     matrix[row][col] = 1;
            // else
            //     matrix[row][col] = 0;
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

bool isIdentityMatrix(const int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            if (i == j && matrix[i][j] != 1)
            {
                return false;  // Diagonal elements should be 1
            }
            else if (i != j && matrix[i][j] != 0)
            {
                return false;  // Non-diagonal elements should be 0
            }
        }
    }
    return true;  // All conditions are satisfied, it's an identity matrix
}

int main()
{
    // Example matrix (3x3 identity matrix)
    int matrix[MATRIX_SIZE][MATRIX_SIZE];

    fillIdentityMatrix(matrix);
    printMatrix(matrix);
    cout << "===========================\n";

    if (isIdentityMatrix(matrix))
    {
        cout << "The matrix is an identity matrix." << endl;
    }
    else
    {
        cout << "The matrix is not an identity matrix." << endl;
    }
    cout << "===========================\n";
}