#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>

const int MATRIX_ROWS = 3;
const int MATRIX_COLS = 3;

int generateRandomNumber(int from, int to)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(from, to);
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
            std::cout << std::setw(2) << std::setfill('0') << matrix[i][j] << "   ";
        }
        std::cout << std::endl;
    }
}

int findMinimum(const int matrix[MATRIX_ROWS][MATRIX_COLS])
{
    int minimum = matrix[0][0];
    for (int row = 0; row < MATRIX_ROWS; row++)
    {
        for (int col = 0; col < MATRIX_COLS; col++)
        {
            if (matrix[row][col] < minimum)
                minimum = matrix[row][col];
        }
    }
    return minimum;
}

int findMaximum(const int matrix[MATRIX_ROWS][MATRIX_COLS])
{
    int maximum = matrix[0][0];
    for (int row = 0; row < MATRIX_ROWS; row++)
    {
        for (int col = 0; col < MATRIX_COLS; col++)
        {
            if (matrix[row][col] > maximum)
                maximum = matrix[row][col];
        }
    }
    return maximum;
}

int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int matrix[MATRIX_ROWS][MATRIX_COLS];

    fillMatrixWithRandomNumbers(matrix);
    std::cout << "Matrix Elements:\n";
    printMatrix(matrix);
    std::cout << "===========================\n";

    std::cout << "Maximum Element: " << findMaximum(matrix) << std::endl;
    std::cout << "===========================\n";

    std::cout << "Minimum Element: " << findMinimum(matrix) << std::endl;
    std::cout << "===========================\n";

    return 0;
}
