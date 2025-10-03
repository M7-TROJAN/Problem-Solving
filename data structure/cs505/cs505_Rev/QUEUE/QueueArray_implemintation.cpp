#include <iostream>
using namespace std;

template < class T>
class QueueArray {
private:
    T* arr;   // Pointer to dynamic array
    int front, rear, count, maxSize;
public:
    QueueArray(int nElements = 128)
    {
        arr = new T[nElements];
        maxSize = nElements;
        front = 0;
        rear = -1;
        count = 0;
    }

    QueueArray(const QueueArray& original)
    {
        maxSize = original.maxSize;
        front = original.front;
        rear = original.rear;
        count = original.count;
        
        for (int i = 0; i < maxSize; i++)
        {
            arr[i] = original[i];
        }
    }

    ~QueueArray()
    {
        delete [] arr;
    }

    void enqueue(const T& el) {
        if (count == maxSize) {
            cout << "Queue is full!" << endl;
            return;
        }
        rear = (rear + 1) % maxSize;
        arr[rear] = el;
        count++;
    }

    void dequeue(T& el) {
        if (count == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }
        el = arr[front];
        front = (front + 1) % maxSize;
        count--;
    }

    bool IsEmpty() const {
        return count == 0;
    }

    bool IsFull() const {
        return count == maxSize;
    }

    int Length() const {
        return count;
    }
};
int main() {
    QueueArray<int> q(6);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(6);

    cout << "Is Empty?: " << (q.IsEmpty()? "True" : "false") << endl;
    cout << "Is Full?: " << (q.IsFull()? "True" : "false") << endl;

    int el;
    cout << "Elements:\n";
    while (!q.IsEmpty())
    {
        q.dequeue(el);
        cout << el << endl;
    }
}

