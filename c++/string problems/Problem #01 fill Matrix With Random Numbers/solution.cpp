/*
program that generates a 3x3 matrix filled with random numbers between 1 and 100 and then prints the matrix.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int generateRandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void fillMatrixWithRandomNumbers(int matrix[3][3], const short &rows, const short &cols)
{
    for (short i = 0; i < rows; i++)
        for (short j = 0; j < cols; j++)
        {
            matrix[i][j] = generateRandomNumber(1, 100);
        }
}

void PrintMatrix(int matrix[3][3], const short &rows, const short &cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << setw(3) << matrix[i][j] << "   ";
        }
        cout << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int arrayOfRandomNumbers[3][3];
    fillMatrixWithRandomNumbers(arrayOfRandomNumbers, 3, 3);
    PrintMatrix(arrayOfRandomNumbers, 3, 3);
    system("pause>0");
}
