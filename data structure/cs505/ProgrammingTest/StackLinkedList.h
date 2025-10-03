#pragma once
#include <iostream>
using namespace std;

template <class T>
class StackLinkedList {
private:
    class Node {
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
        if (IsEmpty())
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