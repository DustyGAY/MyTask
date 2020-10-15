#pragma once
#ifndef LINKLIST_NODE_H
#define LINKLIST_NODE_H

template <class T>
struct Node {
    T element;
    Node<T>* next;
};

#endif //LINKLIST_NODE_H
