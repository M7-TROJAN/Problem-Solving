
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
void PrintMatrix(int matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
            cout << setw(2) << setfill('0') << matrix[i][j] << "   ";
        cout << "\n";
    }
}
bool IsNumberInMatrix(int matrix[3][3], int Number, short Rows, short Cols)
{
    short NumberCount = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (matrix[i][j] == Number)
            {
                return true;
            };
        }
    }
    return false;
}

void PrintIntersectedNumbers(int matrix1[3][3], int matrix2[3][3], short Rows, short Cols)
{
    int Number;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Number = matrix1[i][j];
            if (IsNumberInMatrix(matrix2, Number, Rows, Cols))
                cout <<  Number << "   ";
        }
    }
}
int main()
{
    int matrix1[3][3] = {{77, 5, 12}, {22, 20, 1}, {1, 0, 9}};
    int matrix2[3][3] = {{5, 80, 90}, {22, 77, 1}, {10, 8, 33}};

    cout << "Matrix1 Elements:\n";
    PrintMatrix(matrix1, 3, 3);
    cout << "===========================\n";

    cout << "Matrix1 Elements:\n";
    PrintMatrix(matrix2, 3, 3);
    cout << "===========================\n";

    cout << "Intersected Numbers are:\n";
    PrintIntersectedNumbers(matrix1, matrix2, 3, 3);
}