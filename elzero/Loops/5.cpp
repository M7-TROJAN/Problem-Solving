#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

int main()
{
  for (int i = 0 ; i < 30 ; i+=3)
    cout << i << " ";

  cout << endl;

  int i = 0;
  while ( i < 30)
  {
    cout << i << " ";
    i+=3;
  }


}

// Output Needed 0 3 6 9 12 15 18 21 24 27