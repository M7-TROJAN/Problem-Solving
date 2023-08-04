#include <iostream>
using namespace std;

class Unique
{
private:
    int id;

public:
    static int next_id;

    Unique()
    {
        id = next_id;
        next_id++;
    }

    int getID()
    {
        return id;
    }

    Unique(const Unique &) = delete;            // Disallow copy construction
    Unique &operator=(const Unique &) = delete; // Disallow copy assignment
};

int Unique::next_id = 1;

int main()
{
    Unique unique1;
    Unique unique2;

    // Error: Attempting to use the deleted copy constructor
    // Unique unique3 = unique1;

    // Error: Attempting to use the deleted copy assignment operator
    // unique3 = unique1;

    cout << "unique1 id: " << unique1.getID() << endl;
    cout << "unique2 id: " << unique2.getID() << endl;

    return 0;
}
