#include <iostream>
#include <string>
using namespace std;

template <class T>
class StackArray {
private:
    T* arr;
    int capacity;
    int topIndex;
    void resize() {
        capacity *= 2;
        T* newArray = new T[capacity];
        for (int i = 0; i <= topIndex; i++)
        {
            newArray[i] = arr[i];
        }
        delete [] arr;
        arr= newArray;
    }
public:
    StackArray(int initialCapacity = 10) : capacity(initialCapacity), topIndex(-1) 
    {
        arr = new int[capacity];
    }

    ~StackArray() {
        delete [] arr;
    }

    void Push(const T& value)
    {
        if(IsFull())
            resize();
        arr[++topIndex] = value;
    }

    void Pop()
    {
        if (IsEmpty())
        {
            return;
            // throw underflow_error("Stack underflow: Cannot pop from an empty stack.");
        }
        topIndex--;
    }

    T Top()
    {
        if (IsEmpty())
        {
            throw underflow_error("Stack is empty: No top element.");
        }
        return arr[topIndex];
    }

    bool IsFull() const {
        return topIndex + 1 == capacity;
    }

    int Size() const {
        return topIndex + 1;
    }

    int Capacity() const {
        return capacity;
    }
    
    bool IsEmpty() const
    {
        return topIndex == -1;
    }

    bool Contains(const T& value) const
    {
        if(IsEmpty) return false;

        for (int i = 0; i <= topIndex; i++)
        {
            if(arr[i] == value)
                return true;
        }
        return false;
    }

    void Shrink() {
        if (Size() <= capacity / 4 && capacity > 10) {
            capacity /= 2;
            T* newArray = new T[capacity];
            for (int i = 0; i <= topIndex; i++) {
                newArray[i] = arr[i];
            }
            delete [] arr;
            arr = newArray;
        }
    }
};

void PrintNGE(int arr[], int size) {
    int* NGE = new int[size];
    StackArray<int> stk;
    for (int i = size-1; i >= 0; i--)
    {
        int nge = 0;
        while (!stk.IsEmpty() && stk.Top() <= arr[i])
        {
            stk.Pop();
        }
        NGE[i] = stk.IsEmpty()? -1 : stk.Top();
        stk.Push(arr[i]);
    }
    
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " -> " << NGE[i] << endl;
    }
    delete [] NGE;
}

int main() {
    StackArray<int> stk;

    cout << "IsEmpty: " << stk.IsEmpty() << endl;
    cout << "IsFull: " << stk.IsFull() << endl;
    cout << "Capacity: " << stk.Capacity() << endl;
    cout << "Size: " << stk.Size() << endl;
    cout << "==================================\n";

    stk.Push(1);
    stk.Push(2);
    stk.Push(3);
    stk.Push(4);
    stk.Push(5);
    stk.Push(6);
    stk.Push(7);
    stk.Push(8);
    stk.Push(9);
    stk.Push(10);
    stk.Push(11);
    
    cout << "IsEmpty: " << stk.IsEmpty() << endl;
    cout << "IsFull: " << stk.IsFull() << endl;
    cout << "Capacity: " << stk.Capacity() << endl;
    cout << "Size: " << stk.Size() << endl;

    cout << "Elements:\n";
    while (!stk.IsEmpty())
    {
        cout << stk.Top() << endl;
        stk.Pop();
    }

    stk.Shrink();

    cout << "==================================\n";
    cout << "IsEmpty: " << stk.IsEmpty() << endl;
    cout << "IsFull: " << stk.IsFull() << endl;
    cout << "Capacity: " << stk.Capacity() << endl;
    cout << "Size: " << stk.Size() << endl;

    int arr[] = {1, 0, 5, 400, 2, 1, 15, 900, 20};
    PrintNGE(arr, 9);
}