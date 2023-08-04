#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
using namespace std;

const int MATRIX_ROWS = 3;
const int MATRIX_COLS = 3;

int get_int(const std::string &message = "")
{
    int number = 0;
    do
    {
        // Read an integer value from the user
        std::cout << message;
        std::cin >> number;

        // Check if the input was invalid (i.e. not an integer)
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000000, '\n');
            cout << "Invalid input. Please enter a valid integer.\n";
            continue;
        }
        break;
    } while (true);
    return number;
}

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

int CountNumberInMatrix(const int matrix[MATRIX_ROWS][MATRIX_COLS], int val)
{
    int counter = 0;
    for (int row = 0; row < MATRIX_ROWS; row++)
    {
        for (int col = 0; col < MATRIX_COLS; col++)
        {
            if (matrix[row][col] == val)
                counter++;
        }
    }
    return counter;
}

int main()
{
    int matrix[MATRIX_ROWS][MATRIX_COLS];

    fillMatrixWithRandomNumbers(matrix);
    cout << "Matrix Elements:\n";
    printMatrix(matrix);
    cout << "===========================\n";

    int number = get_int("Enter the number to count in matrix: ");

    cout << "\nNumber " << number << " count in matrix is " << CountNumberInMatrix(matrix, number) << " Times.";

    return 0;
}
