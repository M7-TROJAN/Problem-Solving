#include <iostream>
#include <string>
using namespace std;

template <class T>
class StackLinkedList {
private:
    class Node
    {
    public:
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };
    Node* topNode;
    int count;
public:
    StackLinkedList() : topNode(nullptr), count(0) {}
    ~StackLinkedList()
    {
        while (!IsEmpty())
        {
            Pop();
        }
    }
    void Push(const T& data) {
        Node* newNode = new Node(data);
        newNode->next = topNode;
        topNode = newNode;
        ++count;
    }

    void Pop() {
        if(IsEmpty())
        {
            cout << "Stack Is Empty. cannot pop." << endl;
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        count--;
    }

    T Top() {
        if (IsEmpty())
        {
            throw underflow_error("Stack is empty: No top element.");
        }
        return topNode->data;
    }

    bool IsEmpty() const {
        return topNode == nullptr;
    }

    int Size() const {
        return count;
    }
};

void PrintNGE(int arr[], int size) {
    int* NGE = new int[size];
    StackLinkedList<int> stk;

    for (int i = size - 1; i >= 0; i--) {
        int nge = -1;

        while (!stk.IsEmpty() && stk.Top() <= arr[i]) {
            stk.Pop();
        }

        NGE[i] = stk.IsEmpty() ? -1 : stk.Top();

        stk.Push(arr[i]);
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " -> " << NGE[i] << endl;
    }

    delete[] NGE;
}


int main() {
    StackLinkedList<int> stk;

    cout << "IsEmpty: " << stk.IsEmpty() << endl;
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
    cout << "Size: " << stk.Size() << endl;

    cout << "Elements:\n";
    while (!stk.IsEmpty())
    {
        cout << stk.Top() << endl;
        stk.Pop();
    }

    cout << "==================================\n";
    cout << "IsEmpty: " << stk.IsEmpty() << endl;
    cout << "Size: " << stk.Size() << endl;

    int arr[] = {1, 0, 5, 400, 2, 1, 15, 900, 20};
    PrintNGE(arr, 9);
}