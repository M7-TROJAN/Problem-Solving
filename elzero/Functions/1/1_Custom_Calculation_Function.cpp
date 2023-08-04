#include <iostream>
using namespace std;

// Write Your Function Here
int calcspecial(int num1, int num2)
{
    if (num1 == num2)
        return num1 + num2;

    else if (num1 > num2)
        return num1 - num2;

    return num2 - num1;
}
int main()
{
    cout << calcspecial(40, 40) << "\n";   // First = Second -> 40 + 40 = 80
    cout << calcspecial(200, 50) << "\n";  // First > Second -> 200 - 50 = 150
    cout << calcspecial(100, 300) << "\n"; // First < Second -> 300 - 100 = 200
    return 0;
}