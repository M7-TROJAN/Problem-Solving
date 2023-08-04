#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

int main()
{
  // Output Needed 2  6  14  30  62  126

  // العلاقة بين الارقام هي ان كل رقم بيتجمع علي نفسه وبعدين بنضيف عليه 2
  /*
  ! ex:
    i = 2
    i = (i + i) + 2
    i = 2+2+2  = 6

    i = 6
    i = (i + i) + 2
    i = 6+6+2  = 14 
  */

  for ( int i = 2 ; i <= 126 ; i += (i+2) )
    cout << i << "  ";

  cout << "\n";

  int i = 2;
  while (i <= 126)
  {
    cout << i << "  ";
    i+= (i+2);
  }
}
// Output Needed
/*
2
6
14
30
62
126
*/