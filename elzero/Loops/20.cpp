#include <iostream>
#include <algorithm>
#include <array>
#include <cstring>
using namespace std;
int main()
{
  string names[] = {"Osama", "Ahmed", "Mahmoud", "Hagar", "Eman", "Salwa"};
// لنطبع فقط الأسماء التي تتكون من 5 حروف

// Output Needed
/*
"Osama"
"Ahmed"
"Hagar"
"Salwa"
*/

  int n = sizeof(names) / sizeof(names[0]);
  for (int i = 0; i < n; i++)
  {
    if (names[i].size() == 5)
      cout << names[i] << endl;
  }
  
}