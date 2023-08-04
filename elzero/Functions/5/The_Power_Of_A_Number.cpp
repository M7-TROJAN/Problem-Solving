#include <iostream>
using namespace std;

// Write Your Function Here
void power(int base, int exponent) {
    if (exponent == 0)
    {
        cout << 1 << endl;
        return;
    }

    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    cout << result << endl;
}
int main()
{
    power(2, 5); // 32

    return 0;
}