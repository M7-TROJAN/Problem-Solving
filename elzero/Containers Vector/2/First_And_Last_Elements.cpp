#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> numbers = { 10, 20, 30, 40 };
    cout << "First Element Is:\n";
    cout << numbers[0] << "\n";
    cout << numbers.at(0) << "\n";
    cout << numbers.front() << "\n";
    cout << *numbers.begin() << "\n";

    cout << "Last Element Is:\n";
    cout << numbers[numbers.size()-1] << "\n";
    cout << numbers.at(numbers.size()-1) << "\n";
    cout << numbers.back() << "\n";
    cout << *(numbers.end()-1) << "\n";

}