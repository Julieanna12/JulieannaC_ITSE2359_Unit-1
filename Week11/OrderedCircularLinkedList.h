#ifndef ORDEREDCIRCULARLINKEDLIST_H
#define ORDEREDCIRCULARLINKEDLIST_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class OrderedCircularLinkedList {
private:
    Node* head;

public:
    OrderedCircularLinkedList() : head(nullptr) {}

    // Insert function to maintain ascending order
    void insertOrdered(int newData) {
        Node* newNode = new Node(newData);

        // If the list is empty, initialize the head and set the circular link
        if (!head) {
            head = newNode;
            head->next = head;  // Circular link
            return;
        }

        Node* current = head;
        Node* prev = nullptr;

        // search the list to find the right position to insert
        do {
            if (current->data >= newData) {
                break;
            }
            prev = current;
            current = current->next;
        } while (current != head);

        // Insert at the beginning or in between nodes
        if (prev == nullptr) {  // Insert before the head
            newNode->next = head;
            // Find last node to update its next pointer
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            head = newNode;
        } else {  // Insert after 'prev' node
            prev->next = newNode;
            newNode->next = current;
        }
    }

    // Print function to display the circular list
    void printList() {
        if (!head) return;

        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
};

#endif
