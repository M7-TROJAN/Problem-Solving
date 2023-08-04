#include <iostream>
#include <algorithm>
#include <array>
#include <cstring>
using namespace std;

int main()
{
  // Friends Array
  string friends[] = {"Ahmed", "Mohamed", "Sayed", "Gamal"};
  int n = sizeof(friends) / sizeof(friends[0]);
  for (int i = 1 ; i < n ; i++)
  {
      if(i == n-1)
        break;
      cout << friends[i] << "\n";
  }

// Output Needed
/*
  "Mohamed"
  "Sayed"
*/
}