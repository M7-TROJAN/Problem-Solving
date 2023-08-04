#include <iostream>
using namespace std;

// Write Your Function Here
int books(int smallBooks, int mediumBooks, int largeBooks, int shelves)
{
    int available_Space = shelves * 20;

    int total_box_space = (smallBooks * 2) + (mediumBooks * 4) + (largeBooks * 6);

    return max(0, available_Space - total_box_space);


}
int main()
{
    cout << books(10, 4, 3, 4) << "\n"; // 26
    cout << books(10, 4, 3, 2) << "\n"; // 0
    return 0;
}