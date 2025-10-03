#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class LinkedList {
private:
    class Node {
    public:
        T data;
        Node* next;
        explicit Node(const T& data) : data(data), next(nullptr) {}
    };

    Node* head;

    int size(Node* list) const {
        if (!list) return 0;
        return 1 + size(list->next);
    }

public:
    LinkedList() : head(nullptr) {}

    template<typename... Args>
    LinkedList(const T& first, const Args&... args) : head(nullptr) {
        insertAtEnd(first);
        (insertAtEnd(args), ...);
    }

    ~LinkedList() {
        Clear();
    }

    void insertAtBeginning(const T& data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(const T& data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void deleteNode(const T& data) {
        if (!head) return;

        if (head->data == data) {
            Node* nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->data != data) {
            temp = temp->next;
        }

        if (!temp->next) return;

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;

        delete nodeToDelete;
    }

    bool isEmpty() const {
        return !head;
    }

    int length() const {
        return size(head);
    }

    void printList() const {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr\n";
    }
    void Clear() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }
};

#endif // LINKED_LIST_H