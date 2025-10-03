#include <iostream>
using namespace std;

class source
{
private:
    /* data */
public:
    void print()
    {
        cout << "Hello, TROJAN\n";
    }
    int x;
};

int main() {
    int *arr;
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = i*2;
    }
    for (int i = 0; i < size; i++)
    {
        if (i+1 < size)
        {
            cout << arr[i] << ", ";
        }
        else
            cout << arr[i] << endl;
    }

    source *s = new source();
    s->x = 10;
    s->print();
    cout << s->x;
    delete s;
}