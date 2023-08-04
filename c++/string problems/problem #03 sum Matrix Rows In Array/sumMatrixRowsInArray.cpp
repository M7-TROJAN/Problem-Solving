#include <iostream>
#include <iomanip>
#include <random>
using namespace std;

const int MATRIX_SIZE = 3;

int generateRandomNumber(int from, int to)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(from, to);
    return dis(gen);
}

void fillMatrixWithRandomNumbers(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            matrix[i][j] = generateRandomNumber(1, 100);
        }
    }
}

void printMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

int rowSum(int matrix[MATRIX_SIZE][MATRIX_SIZE], int rowNumber)
{
    int sum = 0;
    for (int j = 0; j < MATRIX_SIZE; j++)
    {
        sum += matrix[rowNumber][j];
    }
    return sum;
}

void sumMatrixRowsInArray(int matrix[MATRIX_SIZE][MATRIX_SIZE], int rowSums[MATRIX_SIZE])
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        rowSums[i] = rowSum(matrix, i);
    }
}

void printRowSumsArray(int rowSums[MATRIX_SIZE])
{
    cout << "\nThe following are the sum of each row in the matrix:\n";
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        cout << "Row " << i + 1 << " Sum = " << rowSums[i] << endl;
    }
}

int main()
{
    srand(static_cast<unsigned>(time(NULL)));

    int matrix[MATRIX_SIZE][MATRIX_SIZE];
    int rowSums[MATRIX_SIZE];

    fillMatrixWithRandomNumbers(matrix);

    cout << "\nThe following is a " << MATRIX_SIZE << "x" << MATRIX_SIZE << " random matrix:\n";
    printMatrix(matrix);

    sumMatrixRowsInArray(matrix, rowSums);

    printRowSumsArray(rowSums);

    cin.get();
    return 0;
}
