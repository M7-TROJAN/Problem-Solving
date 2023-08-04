#include <vector>
using namespace std;

vector<vector<int>> matrix_multiplication(vector<vector<int>> &a, vector<vector<int>> &b, size_t n)
{
    std::vector<vector<int>> c(n, vector<int>(n, 0));
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            for (size_t k = 0; k < n; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return c;
}