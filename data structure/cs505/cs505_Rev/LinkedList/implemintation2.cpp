#include <iostream>
using namespace std;

template<class keyType, class dataType>
class List {
private:
    // Node Class
    class Node {
    public:
        keyType key;
        dataType data;
        Node *next;
    };

    typedef Node* NodePointer;

    NodePointer head, cursor, prev;

public:
    List() : head(NULL), cursor(NULL), prev(NULL) {}

    ~List() { 
        makeListEmpty(); 
    }

    bool listIsEmpty() const { 
        return head == NULL; 
    }

    bool curIsEmpty() const { 
        return cursor == NULL; 
    }

    void toFirst() { 
        cursor = head; prev = NULL; 
    }

    bool atFirst() const { 
        return cursor == head; 
    }

    void advance() { 
        prev = cursor; cursor = cursor->next; 
    }

    void toEnd() {
        while (cursor != NULL && cursor->next != NULL) 
            advance(); 
    }

    bool atEnd() const { 
        return cursor == NULL || cursor->next == NULL; 
    }

    int listSize() const {
        NodePointer temp = head;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void updateData(const dataType &d) {
        if (!curIsEmpty())
            cursor->data = d;
    }

    void retrieveData(dataType &d) const {
        if (!curIsEmpty())
            d = cursor->data;
    }

    void insertFirst(const keyType &k, const dataType &d) {
        NodePointer newNode = new Node;
        newNode->key = k;
        newNode->data = d;
        newNode->next = head;
        head = newNode;
        cursor = head;
        prev = NULL;
    }

    void insertAfter(const keyType &k, const dataType &d) {
        NodePointer newNode = new Node;
        newNode->key = k;
        newNode->data = d;
        newNode->next = cursor->next;
        cursor->next = newNode;
        advance();
    }

    void insertBefore(const keyType &k, const dataType &d) {
        if (listIsEmpty()) return;
        if (atFirst())
            insertFirst(k, d);
        else {
            NodePointer newNode = new Node;
            newNode->key = k;
            newNode->data = d;
            newNode->next = cursor;
            prev->next = newNode;
        }
    }

    void insertEnd(const keyType &k, const dataType &d) {
        if (listIsEmpty())
            insertFirst(k, d);
        else {
            toEnd();
            insertAfter(k, d);
        }
    }

    void deleteNode() {
        if (curIsEmpty()) return;
        if (atFirst())
            deleteFirst();
        else {
            prev->next = cursor->next;
            delete cursor;
            cursor = prev->next;
        }
    }

    void deleteFirst() {
        if (listIsEmpty()) return;
        NodePointer temp = head;
        head = head->next;
        if (cursor == temp)
            cursor = head;
        delete temp;
    }

    void deleteEnd() {
        if (listIsEmpty()) return;
        if (head->next == NULL)
            deleteFirst();
        else {
            toEnd();
            deleteNode();
        }
    }

    void makeListEmpty() {
        while (!listIsEmpty())
            deleteFirst();
    }

    bool search(const keyType &k) {
        toFirst();
        while (cursor != NULL) {
            if (cursor->key == k)
                return true;
            advance();
        }
        return false;
    }

    void orderInsert(const keyType &k, const dataType &d) {
        if (listIsEmpty() || k <= head->key)
            insertFirst(k, d);
        else {
            toFirst();
            while (cursor->next != NULL && cursor->next->key < k) {
                advance();
            }
            insertAfter(k, d);
        }
    }

    void traverse() const {
        NodePointer temp = head;
        while (temp != NULL) {
            cout << "Key: " << temp->key << ", Data: " << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main() {
    List<int, string> myList;

    myList.insertFirst(1, "Data1");
    myList.insertEnd(2, "Data2");
    myList.insertEnd(3, "Data3");

    cout << "Traversing the list:" << endl;
    myList.traverse();

    cout << "Deleting the first node..." << endl;
    myList.deleteFirst();

    cout << "Traversing the list again:" << endl;
    myList.traverse();

    cout << "Inserting before the current node..." << endl;
    myList.insertBefore(0, "NewData");

    cout << "Final list:" << endl;
    myList.traverse();

    return 0;
}