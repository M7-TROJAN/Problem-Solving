#include <string>
using namespace std;
bool feast(string beast, string dish)
{
    return beast.front() == dish.front() && beast.back() == dish.back();
}