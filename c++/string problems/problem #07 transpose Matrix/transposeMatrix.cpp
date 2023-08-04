#include <iostream>
#include <iomanip>

using namespace std;

const short MATRIX_ROWS = 3;
const short MATRIX_COLS = 3;

void fillMatrixWithOrderedNumbers(int matrix[MATRIX_ROWS][MATRIX_COLS])
{
    int counter = 1;
    for (short row = 0; row < MATRIX_ROWS; row++)
    {
        for (short col = 0; col < MATRIX_COLS; col++)
        {
            matrix[row][col] = counter++;
        }
    }
}

void printMatrix(const int matrix[MATRIX_ROWS][MATRIX_COLS])
{
    for (short row = 0; row < MATRIX_ROWS; row++)
    {
        for (short col = 0; col < MATRIX_COLS; col++)
        {
            cout << setw(3) << matrix[row][col] << " ";
        }
        cout << endl;
    }
}

void transposeMatrix(const int matrix[MATRIX_ROWS][MATRIX_COLS], int transposedMatrix[MATRIX_COLS][MATRIX_ROWS])
{
    for (short i = 0; i < MATRIX_ROWS; i++)
    {
        for (short j = 0; j < MATRIX_COLS; j++)
        {
            transposedMatrix[i][j] = matrix[j][i];
        }
    }
}

int main()
{
    int matrix[MATRIX_ROWS][MATRIX_COLS];
    int transposedMatrix[MATRIX_COLS][MATRIX_ROWS];
    fillMatrixWithOrderedNumbers(matrix);
    cout << "\nThe following is a " << MATRIX_ROWS << "x" << MATRIX_COLS << " ordered matrix:\n";
    printMatrix(matrix);
    transposeMatrix(matrix, transposedMatrix);
    cout << "\n\nThe following is the transposed matrix:\n";
    printMatrix(transposedMatrix);

    return 0;
}
