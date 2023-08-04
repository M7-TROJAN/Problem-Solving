#include <iostream>
#include <algorithm>
#include <array>
#include <cstring>
using namespace std;
void print_row(int n)
{
  // print this sign = with the same number of n and then print new line
  for(int i = 0 ; i < n ; i++)
  {
    cout<<"=";
  }
  cout<<"\n";
}

int main()
{
  // Friends Array
  string friends[] = {"Ahmed", "Osama", "Ameer" , "mahmoud" , "mattar"};
  
  // solution:

  // get the count of friends array elements
  int n = sizeof(friends) / sizeof(friends[0]);

  for (int i = 0 ; i < n; i++)
  {
    // get the number of characters of index number i
    int str_count = friends[i].size();

    print_row(str_count+4); // print this sign =  with the same number of characters + 4
    cout << "= " << friends[i] <<" =\n";
    print_row(str_count + (str_count*2) +2);

    cout << "= ";
    for (size_t j = 0; j < str_count ; j++)
    {
      cout << friends[i][j];
      if (j < str_count-1) // check if we reach the last index of the string
        cout << ", ";
    }
    cout << " =\n";
    print_row(str_count + (str_count*2) +2);
    cout << "\n";
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