#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        if (!current->isInt) {
            delete current->data.listValue;
        }
        delete current;
        current = next;
    }
}

void LinkedList::append(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
    //std::cout << value << "inserted"<<std::endl;
}

void LinkedList::append(LinkedList* list) {
    Node* newNode = new Node(list);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

LinkedList::LinkedList(const LinkedList& other) : head(deepCopy(other.head)) {}

LinkedList& LinkedList::operator=(const LinkedList& other) {
    if (this != &other) {
        Node* newHead = deepCopy(other.head);
        // Clean up the existing list
        this->~LinkedList();
        head = newHead;
    }
    return *this;
}

Node* LinkedList::deepCopy(const Node* node) {
    if (node == nullptr) return nullptr;

    Node* newNode = new Node(node->data.intValue);
    newNode->isInt = node->isInt;
    if (!node->isInt) {
        newNode->data.listValue = new LinkedList(*node->data.listValue);
    }
    newNode->next = deepCopy(node->next);
    return newNode;
}

void LinkedList::appendList(const LinkedList& first, const LinkedList& second) {
    Node* newHead = deepCopy(first.head);

    Node* current = newHead;
    while (current != nullptr && current->next != nullptr) {
        current = current->next;
    }

    if (current != nullptr) {
        current->next = deepCopy(second.head);
    } else {
        newHead = deepCopy(second.head);
    }

    this->~LinkedList();
    head = newHead;
}


bool LinkedList::isEmpty() const {
    return head == nullptr;
}

std::variant<int, LinkedList*> LinkedList::getElementAt(int index) const {
    Node* current = head;
    int count = 0;

    while (current != nullptr && count < index) {
        current = current->next;
        ++count;
    }
//std::cout << "count:" << count << std::endl;
    if (current != nullptr) {
        if (current->isInt) {
            return current->data.intValue;
        } else {
            return current->data.listValue;
        }
    }
}

void LinkedList::setElementAt(int index, const std::variant<int, LinkedList*>& newValue) {
    Node* current = head;
    int count = 0;

    while (current != nullptr && count < index) {
        current = current->next;
        ++count;
    }

    if (current != nullptr) {
        if (!current->isInt) {
            delete current->data.listValue;
        }

        if (std::holds_alternative<int>(newValue)) {
            //std::cout << "if clause" << std::get<int>(newValue) << std::endl;
            current->data.intValue = std::get<int>(newValue);
            current->isInt = true;
        } else {
            current->data.listValue = std::get<LinkedList*>(newValue);
            current->isInt = false;
        }
    }
}


void LinkedList::print() const {
    Node* current = head;
    while (current != nullptr) {
        if (current->isInt) {
            std::cout << current->data.intValue;
        } else {
            std::cout << "[";
            current->data.listValue->print();
            std::cout << "]";
        }

        if (current->next != nullptr) {
            std::cout << " -> ";
        }
        current = current->next;
    }
}
