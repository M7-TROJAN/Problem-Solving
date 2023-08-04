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
            printf("%.2d   ",matrix[i][j]);
        }
        cout << endl;
    }
}

void multiplyMatrix(const int matrix1[MATRIX_ROWS][MATRIX_COLS], const int matrix2[MATRIX_ROWS][MATRIX_COLS], int matrixResult[MATRIX_ROWS][MATRIX_COLS])
{
    for(int i = 0; i < MATRIX_ROWS; i++ )
    {
        for (int j = 0; j < MATRIX_COLS; j++)
        {
            matrixResult[i][j] = matrix1[i][j] * matrix2[i][j];
        }
    }
}

int main()
{
    srand(static_cast<unsigned>(time(NULL)));

    int matrix1[MATRIX_ROWS][MATRIX_COLS];
    int matrix2[MATRIX_ROWS][MATRIX_COLS];
    int matrixResult[MATRIX_ROWS][MATRIX_COLS];

    fillMatrixWithRandomNumbers(matrix1);
    cout << "\nMatrix 1 Elements:\n";
    printMatrix(matrix1);
    cout << "==================";

    fillMatrixWithRandomNumbers(matrix2);
    cout << "\nMatrix 2 Elements:\n";
    printMatrix(matrix2);
    cout << "==================";

    multiplyMatrix(matrix1, matrix2, matrixResult);
    cout << "\nResults:\n";
    printMatrix(matrixResult);
    cout << "==================\n";


    return 0;
}
