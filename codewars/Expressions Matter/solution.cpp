
#include <algorithm>
using namespace std;
unsigned short expressionsMatter(unsigned short a, unsigned short b, unsigned short c)
{
    int result = 0;

    // Evaluate expressions without brackets
    result = max(result, a + b + c);
    result = max(result, a * b * c);
    result = max(result, a + b * c);
    result = max(result, a * b + c);

    // Evaluate expressions with brackets
    result = max(result, (a + b) * c);
    result = max(result, a * (b + c));

    return result;
}

// .................................................................

#include <algorithm>

unsigned short expressionsMatter(unsigned short a, unsigned short b, unsigned short c)
{
    return std::max({a + b + c, a * (b + c), (a + b) * c, a * b * c, a + b + c});
}
/*

a = 1, b = 2, c = 3;

without brackets:
- a + b + c 
- 1 + 2 + 3 = 6

- a * b * c
- 1 * 2 * 3 = 6

- a + b * c
- 1 + 2 * 3 = 7

- a * b + c
- 1 * 2 + 3 = 5

with brackets

- (a + b) * c
- (1 + 2) * 3
-    3    * 3 = 9

- a * (b + c)
- 1 * (2 + 3) = 5

So the maximum value that you can obtain is 9.
*/