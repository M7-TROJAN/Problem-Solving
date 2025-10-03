#include <iostream>
using namespace std;

template< class T>
class QueueL {
private:
    class Node
    {
    public:
        T data;
        Node* next;
        Node(const T& value)
        {
            data = value;
            next = NULL;
        }
    };
    Node* front;
    Node* rear;
    int length;
public:
    QueueL()
    {
        front = NULL;
        rear = NULL;
        length = 0;
    }
    ~QueueL()
    {
        clear();
    }

    void enqueue(T data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        length++;
    }

    void dequeue(T& el) {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        el = front->data;

        Node* temp = front;
        front = front->next;
        delete temp;

        length--;

        if (front == nullptr) {
            rear = nullptr;
        }
    }

    void Front(T& data) 
    {
        if(front != NULL)
            data = front->data;
    }

    bool isEmpty() const {
        return front == NULL;
    }

    int Length() const {
        return length;
    }

    void clear()
    {
        Node* temp;
        while (front != NULL)
        {
            temp = front;
            front = front->next;
            delete temp;
        }
        length = 0;
    }
};
int main() {
    QueueL<int> q;

    cout << "Is Empty?: " << (q.isEmpty()? "True" : "false") << endl;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(6);

    cout << "Is Empty?: " << (q.isEmpty()? "True" : "false") << endl;

    int el;
    cout << "Elements:\n";
    while (!q.isEmpty())
    {
        q.dequeue(el);
        cout << el << endl;
    }
}

