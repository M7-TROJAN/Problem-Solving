/*
To get the count of rows in a 2D array in C++ with dynamic method, you can divide the total size of the array by the size of each row.
To get the count of columns in a 2D array in C++, you can divide the size of a row by the size of each element
*/
#include <iostream>
int main() {

    int arr[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int rowCount = sizeof(arr) / sizeof(arr[0]);
    int colCount = sizeof(arr[0]) / sizeof(arr[0][0]);


    std::cout << "Number of rows: " << rowCount << std::endl;
    std::cout << "Number of columns: " << colCount << std::endl;

    std::cout << "Array Elements: " << std::endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            std::cout << arr[i][j] << " ";
        std::cout << "\n";
    }
    return 0;
}
