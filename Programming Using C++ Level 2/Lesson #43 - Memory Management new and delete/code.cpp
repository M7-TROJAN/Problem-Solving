#include <iostream>
using namespace std;
int main()
{
    // declare an int pointer
    int *ptrX;
    // declare a float pointer
    float *ptrY;
    // declare a string pointer
    string *ptrS;

    // dynamically allocate memory
    ptrX = new int;
    ptrY = new float;
    ptrS = new string;
    // assigning value to the memory
    *ptrX = 45;
    *ptrY = 58.35f;
    *ptrS = "mahmoud";
    cout << *ptrX << endl;
    cout << *ptrY << endl;
    cout << *ptrS << endl;
    
    // deallocate the memory
    delete ptrX;
    delete ptrY;
    delete ptrS;
    return 0;
}