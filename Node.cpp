//
// Created by Daniel Abraham on 22/11/23.
//
#include "Node.h"
#include "LinkedList.h"

Node::Node(int val) : isInt(true), next(nullptr) {
    data.intValue = val;
}

Node::Node(LinkedList* list) : isInt(false), next(nullptr) {
    data.listValue = list;
}
