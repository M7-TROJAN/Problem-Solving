#include <iostream>
#include <string>
using namespace std;

template <class Type>
class QueueL {
private:
    class Node {
    public:
        Type e;
        Node* next;
    };
    Node* front, *rear;
    int count;

public:
    QueueL() : front(nullptr), rear(nullptr), count(0) {}

    ~QueueL() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void enqueue(Type el) {
        Node* newNode = new Node();
        newNode->e = el;
        newNode->next = nullptr;
        if (queueIsEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }

    void dequeue(Type& el) {
        if (queueIsEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        el = front->e;
        Node* temp = front;
        front = front->next;
        delete temp;
        count--;
        if (front == nullptr) {
            rear = nullptr;
        }
    }

    bool IsEmpty() const {
        return front == nullptr;
    }

    int Length() const {
        return count;
    }
};

int main() {
    
}