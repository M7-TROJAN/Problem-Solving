#include <iostream>
void PrintNumbersFromMtoN(int M, int N) {
    if (M < N)
        return;
    std::cout << M << std::endl;
    PrintNumbersFromMtoN(M - 1, N);
}
int main()
{
    PrintNumbersFromMtoN(10, 1);
}