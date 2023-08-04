#include <iostream>
#include <iomanip>
#include <random>
using namespace std;

const int MATRIX_ROWS = 3;
const int MATRIX_COLS = 3;

int generateRandomNumber(int From, int To)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(From, To);
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

void PrintMatrix(int matrix[MATRIX_ROWS][MATRIX_COLS])
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

int main()
{
    int arrayOfRandomNumbers[MATRIX_ROWS][MATRIX_COLS];
    fillMatrixWithRandomNumbers(arrayOfRandomNumbers);
    PrintMatrix(arrayOfRandomNumbers);
    system("pause>0"); 
    return 0;
}