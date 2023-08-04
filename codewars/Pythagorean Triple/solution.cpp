#include <algorithm>
#include <cmath>
using namespace std;
bool PythagoreanTriple(const int a, const int b, const int c)
{
    int arr[] = {a, b , c};
    sort(arr, arr+3);

    return pow(arr[0],2) + pow(arr[1],2) == pow(arr[2],2) ;

    // or =>  return (arr[0] * arr[0]) + (arr[1] * arr[1]) == (arr[2] * arr[2]) ;
}

// Note: If You don't familiar with the topic of (Pythagorean triple) Visit => https://en.wikipedia.org/wiki/Pythagorean_triple