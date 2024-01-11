//
// Created by Daniel Abraham on 22/11/23.
//

#ifndef MP4_NODE_H
#define MP4_NODE_H

class LinkedList; // Forward declaration

// Define a union to store either an integer or a pointer to a LinkedList
union Data {
    int intValue;
    LinkedList* listValue;
};

class Node {
public:
    Data data;
    bool isInt; // Flag to check if data is an integer or a LinkedList
    Node* next;

    Node(int val);              // Constructor for integer
    Node(LinkedList* list);     // Constructor for LinkedList
};

#endif //MP4_NODE_H
