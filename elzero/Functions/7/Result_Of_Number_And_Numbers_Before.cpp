#include <iostream>
using namespace std;

int beforeResult(int mainNumber, int numbersBefore)
{
    int result = mainNumber;
    for(int i = 1 ; i <= numbersBefore ; i++ )
    {
        result += mainNumber - i;
    }
    return result;
}

int main()
{
    cout << beforeResult(10, 5) << endl; // expected output: 45
    cout << beforeResult(15, 3) << endl; // expected output: 54

    return 0;
}
