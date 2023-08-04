#include <iostream>
#include <iomanip>

using namespace std;

const short MATRIX_ROWS = 3;
const short MATRIX_COLS = 3;

void fillMatrixWithOrderedNumbers(int matrix[MATRIX_ROWS][MATRIX_COLS])
{
    short counter = 1; 
    for (short i = 0; i < MATRIX_ROWS; i++)
    {
        for (short j = 0; j < MATRIX_COLS; j++)
        {
            matrix[i][j] = counter++;
        }
    }
}

void printMatrix(const int matrix[MATRIX_ROWS][MATRIX_COLS])
{
    cout << "\nThe Following Is A " << MATRIX_ROWS << "x" << MATRIX_COLS << " Ordered Matrix:\n";
    for (short i = 0; i < MATRIX_ROWS; i++)
    {
        for (short j = 0; j < MATRIX_COLS; j++)
        {
            cout << setw(3) << matrix[i][j] << "   ";
        }
        cout << endl;
    }
}

int main()
{
    int matrix[MATRIX_ROWS][MATRIX_COLS];
    fillMatrixWithOrderedNumbers(matrix);
    printMatrix(matrix);

    return 0;
}
