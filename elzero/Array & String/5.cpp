#include <iostream>
using namespace std;
int n;
int main()
{
  /* 
  Note:
      Palindrome -->  يعني متناظرة
      متناظرة -->  يعني الاندكس الاول قيمته زي الاندكس الاخير والتاني زي الي قبل الاخير وهكذا
  */

  // Example 1
  int vals1[] = {100, 200, 600, 200, 100};

  // Output: "Array Is Palindrome"
  
  n = sizeof(vals1) / sizeof(vals1[0]); // the number of array elements
  for(int i = 0 ; i < n ; i++)
  {
    if(vals1[i] != vals1[(n - 1) - i]) // check if the indexes is not Palindrome
    {
      cout << "Array Is Not Palindrome";
      break; // break if the indexes is not Palindrome
    }

    if ( i == (n-1)/2 )  // check if we are at the middle index
    {
      cout << "Array Is Palindrome\n";
      break;
    }
  }
//.........................................................
  // Example 2
  int vals2[] = {100, 200, 200, 100};

  // Output: "Array Is Palindrome"

  n = sizeof(vals2) / sizeof(vals2[0]);
  for(int i = 0 ; i < n ; i++)
  {
    if(vals2[i] != vals2[(n - 1) - i]) // check if the indexes is not Palindrome
    {
      cout << "Array Is Not Palindrome";
      break; // break if the indexes is not Palindrome
    }

    if ( i == (n-1)/2 )  // check if we are at the middle index
    {
      cout << "Array Is Palindrome\n";
      break;
    }
  }

//.........................................................
  // Example 3
  int vals3[] = {100, 300, 600, 200, 100};

  // Output: "Array Is Not Palindrome"
  
  n = sizeof(vals3) / sizeof(vals3[0]);
  for(int i = 0 ; i < n ; i++)
  {
    if(vals3[i] != vals3[(n - 1) - i]) // check if the indexes is not Palindrome
    {
      cout << "Array Is Not Palindrome";
      break; // break if the indexes is not Palindrome
    }

    if ( i == (n-1)/2 )  // check if we are at the middle index
    {
      cout << "Array Is Palindrome\n";
      break;
    }
  }
}