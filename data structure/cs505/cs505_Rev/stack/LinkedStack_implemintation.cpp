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
        Node* temp;
        while (topNode)
        {
            temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }
    void Push(const T& data) {
        Node* newNode = new Node(data);
        newNode->next = topNode;
        topNode = newNode;
        ++count;
    }

    void Pop(T& el) {
        if(IsEmpty())
        {
            cout << "Stack Is Empty. cannot pop." << endl;
            return;
        }
        el = topNode->data;
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

    int el;
    cout << "Elements:\n";
    while (!stk.IsEmpty())
    {
        stk.Pop(el);
        cout << el << endl;
    }
}