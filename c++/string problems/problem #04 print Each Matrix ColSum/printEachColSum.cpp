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
            matrix[i][j] = generateRandomNumber(1, 100);
        }
    }
}

void printMatrix(const int matrix[MATRIX_ROWS][MATRIX_COLS])
{
    cout << "\nThe following is a " << MATRIX_ROWS << "x" << MATRIX_COLS << " random matrix:\n";
    for (int i = 0; i < MATRIX_ROWS; i++)
    {
        for (int j = 0; j < MATRIX_COLS; j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int colSum(const int arr[MATRIX_ROWS][MATRIX_COLS], int colNumber)
{
    int sum = 0;
    for (int i = 0; i < MATRIX_ROWS; i++)
    {
        sum += arr[i][colNumber];
    }
    return sum;
}

void printEachColSum(const int arr[MATRIX_ROWS][MATRIX_COLS])
{
    cout << "\nThe following are the sum of each column in the matrix:\n";
    for (int j = 0; j < MATRIX_COLS; j++)
    {
        cout << "Column " << j + 1 << " Sum = " << colSum(arr, j) << endl;
    }
}

int main()
{
    srand(static_cast<unsigned>(time(NULL)));

    int matrixOfRandomNumbers[MATRIX_ROWS][MATRIX_COLS];

    fillMatrixWithRandomNumbers(matrixOfRandomNumbers);

    printMatrix(matrixOfRandomNumbers);

    printEachColSum(matrixOfRandomNumbers);

    return 0;
}
