#include <iostream>
#include <algorithm>
#include <array>
#include <cstring>
using namespace std;

int main()
{
  // Friends Array
  string friends[] = {"Ahmed", "Mohamed", "ameer", "Ashraf", "Amany"};
  int n = sizeof(friends) / sizeof(friends[0]);
  for (size_t i = 0; i < n; i++)
  {
    if ('A' == friends[i][0])
      cout << friends[i] << "\n";
    
  }
  

}
// Output Needed
/*
"Ahmed"
"Ashraf"
"Amany"
*/