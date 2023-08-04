
// Intersected Numbers means => "الارقام المشتركة"
#include <iostream>
#include <vector>
#include <iomanip>
#include <random>
#include <algorithm>
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
            matrix[i][j] = generateRandomNumber(1, 30);
        }
    }
}

void printMatrix(const int matrix[MATRIX_ROWS][MATRIX_COLS])
{
    for (int i = 0; i < MATRIX_ROWS; i++)
    {
        for (int j = 0; j < MATRIX_COLS; j++)
            cout << setw(2) << setfill('0') << matrix[i][j] << "   ";
        cout << endl;
    }
}

vector<int> getIntersectedNumbersInTwoMatrices(int matrix1[MATRIX_ROWS][MATRIX_COLS], int matrix2[MATRIX_ROWS][MATRIX_COLS])
{
    vector<int> intersectedNumbers;
    for (int row = 0; row < MATRIX_ROWS; row++)
    {
        for (int col = 0; col < MATRIX_COLS; col++)
        {
            if (find(&matrix2[0][0], &matrix2[MATRIX_ROWS - 1][MATRIX_COLS - 1] + 1, matrix1[row][col]) != &matrix2[MATRIX_ROWS - 1][MATRIX_COLS - 1] + 1)
            {
                intersectedNumbers.push_back(matrix1[row][col]);
            }
        }
    }
    return intersectedNumbers;
}


int main()
{
    srand(static_cast<unsigned>(time(NULL)));

    int matrix1[MATRIX_ROWS][MATRIX_COLS];
    int matrix2[MATRIX_ROWS][MATRIX_COLS];

    fillMatrixWithRandomNumbers(matrix1);
    fillMatrixWithRandomNumbers(matrix2);

    cout << "Matrix1 Elements:\n";
    printMatrix(matrix1);
    cout << "===========================\n";

    cout << "Matrix2 Elements:\n";
    printMatrix(matrix2);
    cout << "===========================\n";

    vector<int> intersectedNumbers = getIntersectedNumbersInTwoMatrices(matrix1, matrix2);

    if(!intersectedNumbers.empty())
    {
        cout << "Intersected Numbers in the Matrices:\n";
        for (int num : intersectedNumbers)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "No Intersected Numbers in the Matrices.\n";
    }

    return 0;
}


/*
getIntersectedNumbersInTwoMatrices() function explanation:

if (find(&matrix2[0][0], &matrix2[MATRIX_ROWS - 1][MATRIX_COLS - 1] + 1, matrix1[row][col]) != &matrix2[MATRIX_ROWS - 1][MATRIX_COLS - 1] + 1)
{
    intersectedNumbers.push_back(matrix1[row][col]);
}

The expression "find(&matrix2[0][0], &matrix2[MATRIX_ROWS - 1][MATRIX_COLS - 1] + 1, matrix1[row][col])" 
searches for the value "matrix1[row][col]" 
in the range of elements defined by "&matrix2[0][0]" and "&matrix2[MATRIX_ROWS - 1][MATRIX_COLS - 1] + 1".

"&matrix2[0][0]"  is the address of the first element in matrix2, which represents the beginning of the range.

"&matrix2[MATRIX_ROWS - 1][MATRIX_COLS - 1] + 1"  is the address of the last element in matrix2 plus one.
It represents the end of the range.

The "find" function returns an iterator pointing to the first occurrence of the searched value within the specified range.
If the value is not found, it returns the end iterator ("&matrix2[MATRIX_ROWS - 1][MATRIX_COLS - 1] + 1" in this case).

So, the condition "find(...) != &matrix2[MATRIX_ROWS - 1][MATRIX_COLS - 1] + 1" checks if the value matrix1[row][col]
is found in matrix2. If it is found, it means the element is common to both matrices,
and it is added to the intersectedNumbers vector using intersectedNumbers.push_back(matrix1[row][col]).

*/