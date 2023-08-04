#include <iostream>
using namespace std;
// function declaration
void add(int, int);
int main()
{
    add(10, 20);
    return 0;
}
// function Definition
void add(int a, int b)
{
    cout << (a + b);
}