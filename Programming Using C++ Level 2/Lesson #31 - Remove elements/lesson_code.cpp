#include <vector>
#include <iostream>
using namespace std;
int main()
{
    // creat vector
    vector<int> vNumbers;

    // add elements
    vNumbers.push_back(10);
    vNumbers.push_back(20);
    vNumbers.push_back(30);
    vNumbers.push_back(40);
    vNumbers.push_back(50);

    // remove elements using pop_back() Method
    vNumbers.pop_back();
    vNumbers.pop_back();
    vNumbers.pop_back();
    vNumbers.pop_back();
    vNumbers.pop_back();

    if(!vNumbers.empty())
    {
        cout << "Numbers Vector: \n\n";
        for (int &Number : vNumbers)
        {
            cout << Number << endl;
        }
        cout << endl;
    }
    else
    {
        cout << "Vector Is Empty, there are no elements to view.\n";
    }
    return 0;
}