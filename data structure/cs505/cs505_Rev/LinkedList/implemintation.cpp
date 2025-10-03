#include <iostream>
using namespace std;

template<class T>
class LinkedList
{
private:
    class Node
    {
    public:
        T data;
        Node* next;
        Node(const T &value)
        {
            data = value;
            next = NULL;
        }
    };
    Node* head;
public:
    LinkedList()
    {
        head = NULL;
    }

    ~LinkedList()
    {
        clear();
    }

    void insertAtBeginning(const T& data)
    {
        Node* newNode = new Node(data);
        if (!newNode) {
            cerr << "Memory allocation failed!" << endl;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(const T& data)
    {
        if(!head)
        {
            insertAtBeginning(data);
            return;
        }

        Node* newNode = new Node(data);
        if (!newNode) {
            cerr << "Memory allocation failed!" << endl;
            return;
        }
        Node* temp = head;

        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void deleteNode(const T& data)
    {
        if(!head)
            return;

        if (head->data == data) {
            Node* nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;
            return;
        }

        Node* temp = head;

        while (temp->next && temp->next->data != data)
        {
            temp = temp->next;
        }
        
        if(temp->next)
        {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }
        else {
            cout << "Node with data " << data << " not found." << endl;
        }
    }

    void printList() {
        if (isEmpty()) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "{ ";
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL }" << endl;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    int length() {
        Node* temp = head;
        int size = 0;
        while (temp)
        {
            ++size;
            temp = temp->next;
        }
        return size;
    }

    void clear()
    {
        Node* temp = head;
        Node* nodeToDelete;
        while (temp)
        {
            nodeToDelete = temp;
            temp = temp->next;
            delete nodeToDelete;
        }
        head = NULL;
    }
};

int main() {
    LinkedList<int> list;

    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    list.printList();

    list.deleteNode(20);
    list.printList();

    cout << "List length: " << list.length() << endl;
    cout << "Is the list empty? " << (list.isEmpty() ? "Yes" : "No") << endl;

    list.clear();
    list.printList();

    return 0;
}