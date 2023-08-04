#include <iostream>
#include <array>
using namespace std;
int main()
{
  // Do Not Edit The Next 3 Lines
  array<int, 3> oldNums = {10, 20, 30};
  array<int, 3> newNums;

//..............................................
  // Write Your Code Here
  int n = oldNums.size();
  for (size_t i = 0; i < n ; i++)
    newNums[(n-1) - i] = oldNums[i];
//...................................................
  // Do Not Edit The Next 3 Lines
  cout << newNums[0] << "\n"; // 30
  cout << newNums[1] << "\n"; // 20
  cout << newNums[2] << "\n"; // 10

  return 0;
}