#include <iostream>
#include <iomanip>
#include <random>

using namespace std;

const int MATRIX_ROWS = 3;
const int MATRIX_COLS = 3;

int generateRandomNumber(int min, int max)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(min, max);
    return dis(gen);
}

void fillMatrixWithRandomNumbers(int matrix[MATRIX_ROWS][MATRIX_COLS])
{
    for (int row = 0; row < MATRIX_ROWS; row++)
    {
        for (int col = 0; col < MATRIX_COLS; col++)
        {
            matrix[row][col] = generateRandomNumber(1, 100);
        }
    }
}

void printMatrix(const int matrix[MATRIX_ROWS][MATRIX_COLS])
{
    cout << "\nThe following is a " << MATRIX_ROWS << "x" << MATRIX_COLS << " random matrix:\n";
    for (int row = 0; row < MATRIX_ROWS; row++)
    {
        for (int col = 0; col < MATRIX_COLS; col++)
        {
            cout << setw(3) << matrix[row][col] << " ";
        }
        cout << "\n";
    }
}

int getColumnSum(const int matrix[MATRIX_ROWS][MATRIX_COLS], int colNumber)
{
    int sum = 0;
    for (int row = 0; row < MATRIX_ROWS; row++)
    {
        sum += matrix[row][colNumber];
    }
    return sum;
}

void computeColumnSums(const int matrix[MATRIX_ROWS][MATRIX_COLS], int colSums[MATRIX_COLS])
{
    for (int col = 0; col < MATRIX_COLS; col++)
    {
        colSums[col] = getColumnSum(matrix, col);
    }
}

void printColumnSums(const int colSums[MATRIX_COLS], int length)
{
    cout << "\nThe following are the sums of each column in the matrix:\n";
    for (int col = 0; col < length; col++)
    {
        cout << "Column " << col + 1 << " Sum = " << colSums[col] << endl;
    }
}

int main()
{
    srand(static_cast<unsigned>(time(NULL)));

    int matrix[MATRIX_ROWS][MATRIX_COLS];
    int columnSums[MATRIX_COLS];

    fillMatrixWithRandomNumbers(matrix);

    printMatrix(matrix);

    computeColumnSums(matrix, columnSums);
    printColumnSums(columnSums, MATRIX_COLS);

    return 0;
}
