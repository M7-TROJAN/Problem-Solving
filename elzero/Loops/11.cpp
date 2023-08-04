#include <iostream>
#include <algorithm>
#include <array>
#include <cstring>
using namespace std;

int main()
{
  // Friends Array
  string friends[] = {"Ahmed", "Osama", "Ameer"};
  
  // solution
  int n = sizeof(friends) / sizeof(friends[0]);
  for (size_t i = 0; i < n; i++)
  {
    cout << "=========\n"
            "= " << friends[i] <<" =\n"
            "=================\n";
    cout << "= ";
    int str_count = friends[i].size();
    for (size_t j = 0; j < str_count ; j++)
    {
      cout << friends[i][j];
      if (j < str_count-1)
        cout << ", ";
    }
    cout << " =\n";
    cout << "=================\n\n";
  }
}
// Output Needed
/*
=========
= Ahmed =
==================
== A, h, m, e, d =
==================

=========
= Osama =
==================
== O, s, a, m, a =
==================

=========
= Ameer =
==================
== A, m, e, e, r =
==================
*/