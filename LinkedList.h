//
// Created by Daniel Abraham on 22/11/23.
//

#ifndef MP4_LINKEDLIST_H
#define MP4_LINKEDLIST_H

#include "Node.h"
#include <stdexcept>
#include <variant>

class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    LinkedList(const LinkedList& other); // Copy constructor
    LinkedList& operator=(const LinkedList& other); // Copy assignment operator
    ~LinkedList();
    void append(int value);
    bool isEmpty() const;
    void append(LinkedList* list);
    void print() const;
    void appendList(const LinkedList& first, const LinkedList& second);
    std::variant<int, LinkedList*> getElementAt(int index) const;
    void setElementAt(int index, const std::variant<int, LinkedList*>& newValue);
    Node* deepCopy(const Node* node);
};

#endif //MP4_LINKEDLIST_H
