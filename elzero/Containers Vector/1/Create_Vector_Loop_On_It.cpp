#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int>numbers;
    numbers = {100, 200, 300, 400};
    for(auto number :numbers)
    {
        cout << number << " ";
    }
    cout << endl;
    numbers.push_back(500);
    cout << "First Element Is: " << numbers.at(0) << endl;;
    cout << "Last Element Is: " << numbers.back() << "\n";


/*
Output:
    100 200 300 400
    "First Element Is: 100"
    "Last Element Is: 500"
*/
}