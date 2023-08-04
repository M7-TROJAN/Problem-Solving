#include <iostream>
#include <iomanip>
#include <random>
using namespace std;

const int MATRIX_ROWS = 3;
const int MATRIX_COLS = 3;

int generateRandomNumber(int from, int to)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(from, to);
    return dis(gen);
}

void fillMatrixWithRandomNumbers(int matrix[MATRIX_ROWS][MATRIX_COLS])
{
    for (int i = 0; i < MATRIX_ROWS; i++)
    {
        for (int j = 0; j < MATRIX_COLS; j++)
        {
            matrix[i][j] = generateRandomNumber(1, 10);
        }
    }
}

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

int sumMatrixElements(const int matrix[MATRIX_ROWS][MATRIX_COLS])
{
    int result = 0;
    for (int row = 0; row < MATRIX_ROWS; row++)
    {
        for (int col = 0; col < MATRIX_COLS; col++)
        {
            result += matrix[row][col];
        }
    }
    return result;
}

bool AreEqualMatrices(int Matrix1[MATRIX_ROWS][MATRIX_COLS], int Matrix2[MATRIX_ROWS][MATRIX_COLS])
{
    return (sumMatrixElements(Matrix1) == sumMatrixElements(Matrix2));
}
int main()
{
    srand(static_cast<unsigned>(time(NULL)));

    int matrix1[MATRIX_ROWS][MATRIX_COLS];
    int matrix2[MATRIX_ROWS][MATRIX_COLS];

    fillMatrixWithRandomNumbers(matrix1);
    cout << "Matrix1 Elements:\n";
    printMatrix(matrix1);
    cout << "===========================\n";

    fillMatrixWithRandomNumbers(matrix2);
    cout << "Matrix1 Elements:\n";
    printMatrix(matrix2);
    cout << "===========================\n";

    if (sumMatrixElements(matrix1) == sumMatrixElements(matrix2))
        cout << "YES: both matrices are equal.\n";
    else
        cout << "No: matrices are NOT equal.\n";

    return 0;
}
