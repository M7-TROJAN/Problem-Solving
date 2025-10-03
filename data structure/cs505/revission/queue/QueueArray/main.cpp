#include <iostream>
#include <string>
#include <stack>
using namespace std;

template <class Type>
class Queue {
private:
    Type* queue;   // Pointer to dynamic array
    int front, rear, count, MaxSize;

public:
    Queue(int nelements = 128) {
        queue = new Type[nelements];
        front = 0;
        rear = -1;
        count = 0;
        MaxSize = nelements;
    }

    Queue(const Queue<Type>& original) : MaxSize(original.MaxSize), front(original.front), rear(original.rear), count(original.count)
    {
        queue = new Type[MaxSize];

        for (int i = 0; i < MaxSize; i++)
        {
            queue[i] = original.queue[i];
        }
    }

    ~Queue() {
        delete[] queue;
    }

    void enqueue(Type el) {
        if (count == MaxSize) {
            cout << "Queue is full!" << endl;
            return;
        }
        rear = (rear + 1) % MaxSize;
        queue[rear] = el;
        count++;
    }

    void dequeue(Type& el) {
        if (count == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }
        el = queue[front];
        front = (front + 1) % MaxSize;
        count--;
    }

    bool IsEmpty() const {
        return count == 0;
    }

    int Length() const {
        return count;
    }
};

// Reverse the queue using a stack
void ReverseQueue(Queue<int>& q)
{
    stack<int> stk;
    int el;
    while (!q.IsEmpty())
    {
        q.dequeue(el);
        stk.push(el);
    }
    
    while (!stk.empty())
    {
        el = stk.top();
        stk.pop();
        q.enqueue(el);
    }
}

// A queue (Q) contains an even number of elements. Write a
// function Split (Q,Q1,Q2) to copy the 1st half of (Q) into (Q1) and
// the 2nd half into (Q2), leaving the original queue unchanged.
void Split(const Queue<int>& Q, Queue<int>& Q1, Queue<int>& Q2)
{
    Queue<int> temp = Q; // use the copy constructor

    int length = temp.Length();
    int el;
    for (int i = 0; i < length/2; i++)
    {
        temp.dequeue(el);
        Q1.enqueue(el);
    }
    
    int remain = temp.Length();
    
    for (int i = 0; i < remain; i++)
    {
        temp.dequeue(el);
        Q2.enqueue(el);
    }
}

// Write a recursive function Append (Q1,Q2) to append a queue
// (Q2) to the end of a queue (Q1), leaving Q2 empty.
void Append(Queue<int>& Q1, Queue<int>& Q2)
{
    if(Q2.IsEmpty())
        return;

    int el;
    Q2.dequeue(el);
    Q1.enqueue(el);
    Append(Q1, Q2);
}

// Write a function NthElement (Q) to return the nth element in a
// queue (Q), leaving the queue without that element.

int NthElement(Queue<int>& q, int nthElement)
{
    int length = q.Length();
    int el;
    for (int i = 1; i < length; i++)
    {
        q.dequeue(el);
        if(i != nthElement)
        {
            q.enqueue(el);
        }
        else {
            return el;
        }
    }
}

// Write a boolean function EqualQueues ( Q1 , Q2 ) which receives
// two queues Q1 and Q2 and returns True if they are identical and
// False otherwise. The function should leave the queues unchanged.
bool EqualQueues(const Queue<int>& Q1, const Queue<int>& Q2)
{
    Queue<int> Q3 = Q1; // use copy constructor
    Queue<int> Q4 = Q2; // use copy constructor

    if(Q3.Length() != Q4.Length())
        return false;

    int el1 , el2;
    while (!Q3.IsEmpty() && !Q4.IsEmpty())
    {
        Q3.dequeue(el1);
        Q4.dequeue(el2);
        if(el1 != el2)
            return false;
    }
    return true; // if we reach here that means that two queues are equal;
}

// Implement a method that find the minimum item in a queue
// without changing the queue elements.
int FindMinItem(const Queue<int>& q)
{
    Queue<int> temp(q);
    int el;
    int min;
    temp.dequeue(min);

    while (!temp.IsEmpty())
    {
        temp.dequeue(el);
        if(el < min)
            min = el;
    }
    return min;
}

void SplitEvenOdd(Queue<int>& Q, Queue<int>& Q1, Queue<int>& Q2) {
    int size = Q.Length();
    int element;
    for (int i = 0; i < size; i++) {
        Q.dequeue(element);

        if (element % 2 == 0) {
            Q2.enqueue(element);
        } else {
            Q1.enqueue(element);
        }

        Q.enqueue(element);
    }
}

// Print the queue without modifying it
void PrintQueue(const Queue<int>& q) // Pass by const reference
{
    Queue<int> temp = q; // Create a copy of the queue
    int el;
    while (!temp.IsEmpty())
    {
        temp.dequeue(el);
        cout << el << ", ";
    }
    cout << "\n";
}

int main() {
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(10);
    q.enqueue(0);
    q.enqueue(-1);

    cout << "Original Queue: ";
    PrintQueue(q);

    ReverseQueue(q);

    cout << "Reversed Queue: ";
    PrintQueue(q);

    Queue<int> q1;
    Queue<int> q2;

    Split(q, q1, q2);

    cout << "Queue1: ";
    PrintQueue(q1);

    cout << "Queue2: ";
    PrintQueue(q2);

    cout << "q: ";
    PrintQueue(q);

    Append(q1, q2);
    cout << "After Append Q2 to Q1\n";

    cout << "Queue1: ";
    PrintQueue(q1);

    cout << "Queue2: ";
    PrintQueue(q2);

    cout << "Fifth element in q1: " << NthElement(q1, 5) << "\n";

    cout << "Queue1: ";
    PrintQueue(q1);


    Queue<int> q3;
    q3.enqueue(1);
    q3.enqueue(2);
    q3.enqueue(3);
    q3.enqueue(4);
    q3.enqueue(5);
    q3.enqueue(6);
    q3.enqueue(7);
    q3.enqueue(8);
    q3.enqueue(9);
    q3.enqueue(10);

    cout << "Queue3: ";
    PrintQueue(q3);

    Queue<int> q4;
    q4.enqueue(1);
    q4.enqueue(2);
    q4.enqueue(3);
    q4.enqueue(4);
    q4.enqueue(5);
    q4.enqueue(6);
    q4.enqueue(7);
    q4.enqueue(8);
    q4.enqueue(9);
    q4.enqueue(10);

    cout << "Queue4: ";
    PrintQueue(q4);

    cout << "Are Q3 and Q4 Are Equal?: " << EqualQueues(q3, q4) << endl;

    cout << "min Element inside q: " << FindMinItem(q) << endl;

    return 0;
}
