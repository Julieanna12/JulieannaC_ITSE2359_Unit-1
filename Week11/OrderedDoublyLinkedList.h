#ifndef ORDEREDDOUBLYLINKEDLIST_H
#define ORDEREDDOUBLYLINKEDLIST_H

#include <iostream>
using namespace std;

struct DoublyNode {
    int data;
    DoublyNode* next;
    DoublyNode* prev;
    DoublyNode(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class OrderedDoublyLinkedList {
private:
    DoublyNode* head;
    DoublyNode* tail;

public:
    OrderedDoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Insert function to maintain ascending order
    void insertOrdered(int newData) {
        DoublyNode* newNode = new DoublyNode(newData);

        if (!head) {
            head = tail = newNode;
            return;
        }

        if (newData <= head->data) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }

        if (newData >= tail->data) {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
            return;
        }

        DoublyNode* current = head;
        while (current && current->data < newData) {
            current = current->next;
        }

        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
    }

    // Print list forward
    void printForward() {
        DoublyNode* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Print list backward
    void printBackward() {
        DoublyNode* current = tail;
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

#endif
