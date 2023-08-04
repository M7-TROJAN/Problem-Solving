#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
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
    for (int i = 0; i < MATRIX_ROWS; i++)
    {
        for (int j = 0; j < MATRIX_COLS; j++)
        {
            cout << setw(2) << setfill('0') << matrix[i][j] << "   ";
        }
        cout << endl;
    }
}

void printMiddleRowOfMatrix(const int matrix[MATRIX_ROWS][MATRIX_COLS])
{
    short middleRow = MATRIX_ROWS / 2;
    for (short j = 0; j < MATRIX_COLS; j++)
    {
        printf("%02d ", matrix[middleRow][j]);
    }
    cout << endl;
}

void printMiddleColOfMatrix(const int matrix[MATRIX_ROWS][MATRIX_COLS])
{
    short middleCol = MATRIX_COLS / 2;
    for (short i = 0; i < MATRIX_ROWS; i++)
    {
        printf("%02d\n", matrix[i][middleCol]);
    }
}

int main()
{
    srand(static_cast<unsigned>(time(NULL)));

    int matrix[MATRIX_ROWS][MATRIX_COLS];

    fillMatrixWithRandomNumbers(matrix);
    cout << "\nMatrix Elements:\n";
    printMatrix(matrix);
    cout << "===================\n";

    cout << "Middle Row of Matrix is:\n";
    printMiddleRowOfMatrix(matrix);
    cout << "===================\n";

    cout << "Middle Column of Matrix is:\n";
    printMiddleColOfMatrix(matrix);
    cout << "===================\n";

    return 0;
}
