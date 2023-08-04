/*
  Test Case 1
  Number One: 1
  Number Two: 9
  Output: 3, 5, 7

  Test Case 2
  Number One: 2
  Number Two: 15
  Output: 3, 5, 7, 9, 11, 13

  Test Case 3
  Number One: 8
  Number Two: 2
  Output: 3, 5, 7
*/

#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

void check(int &a , int &b)
{
  if (a < b)
    return;
  
  int tmp = a;
  a = b;
  b = tmp;
}
int main()
{
  int start , end;
  cout << "enter two numbers: ";
  cin >> start >> end;
  check(start, end);
  for (int i = start+1 ; i < end; i++)
  {
    if(i%2 != 0)
      cout << i << " ";
  }
}