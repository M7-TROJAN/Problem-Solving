#include <iostream>
#include <iomanip>

using namespace std;

const int MATRIX_ROWS = 3;
const int MATRIX_COLS = 3;

int generateRandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
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

void printMatrix(int matrix[MATRIX_ROWS][MATRIX_COLS])
{
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

int rowSum(int arr[MATRIX_ROWS][MATRIX_COLS], short rowNumber)
{
    int sum = 0;
    for (short j = 0; j < MATRIX_COLS; j++)
    {
        sum += arr[rowNumber][j];
    }
    return sum;
}

void printEachRowSum(int arr[MATRIX_ROWS][MATRIX_COLS])
{
    cout << "\nThe following are the sum of each row in the matrix:\n";
    for (short i = 0; i < MATRIX_ROWS; i++)
    {
        cout << "Row " << i + 1 << " Sum = " << rowSum(arr, i) << endl;
    }
}

int main()
{
    srand(static_cast<unsigned>(time(NULL)));

    int matrixOfRandomNumbers[MATRIX_ROWS][MATRIX_COLS];

    fillMatrixWithRandomNumbers(matrixOfRandomNumbers);

    cout << "\nThe following is a " << MATRIX_ROWS << "x" << MATRIX_COLS << " random matrix:\n";
    printMatrix(matrixOfRandomNumbers);

    printEachRowSum(matrixOfRandomNumbers);

    cin.get();
    return 0;
}
