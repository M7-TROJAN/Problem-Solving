#include <iostream>
#include <algorithm>
#include <array>
#include <cstring>
using namespace std;
int main()
{
  for (int i = 0; i <= 1000; i += 100) // Do Not Edit This Line
{
  // Edit What You Need And Add Your Code
  if (i < 100 || i == 500)
    continue;
  cout << i << "\n";
  if (i == 900)
    break;
}

// Output Needed
/*
100
200
300
400
600
700
800
900
*/
}