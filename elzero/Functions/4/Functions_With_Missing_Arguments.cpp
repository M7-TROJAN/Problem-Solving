#include <iostream>
using namespace std;

// Your Function Here
int calculation(int num1, int num2 = 50, int num3 = 150)
{
    return num1 + num2 + num3;
}
int main()
{
    cout << calculation(50, 100, 150) << "\n"; // 300
    cout << calculation(100, 50) << "\n";      // 300
    cout << calculation(100) << "\n";          // 300
    return 0;
}