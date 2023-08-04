#include <iostream>
using namespace std;
void PrintNumbersFromNtoM(int N, int M)
{
    if (N <= M)
    {
        cout << N << endl;
        PrintNumbersFromNtoM(N + 1, M);
    }
}
int main()
{
    PrintNumbersFromNtoM(1, 10);
    return 0;
}