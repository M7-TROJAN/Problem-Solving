#include <stdio.h>
#include <stdlib.h>

int** matrix_multiplication(int** a, int** b, int n) {
    int** c = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        c[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return c;
}

/*
    Important Note: Please remember to store the returned value from the matrix_multiplication() function in a variable and then free it.

    example:
        int** result = matrix_multiplication(a, b, n);

        Free memory for result matrix
        for (int i = 0; i < n; i++) {
            free(result[i]);
        }
        free(result);
*/