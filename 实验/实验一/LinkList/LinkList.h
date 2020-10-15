#pragma once
#ifndef LINKLIST_LINKLIST_H
#define LINKLIST_LINKLIST_H
#include "Node.h"

template <class T>
class LinkList {
private:
    Node<T>* head;
public:
    LinkList();
    LinkList(T* items, int len);
    ~LinkList();
    int Length() const;
    T Get(int index) const;
    int Locate(T item) const;
    void Insert(T item, int index);
    T Delete(int index);
    void PrintList() const;
    void Merge(LinkList<T> &l);
};


#endif //LINKLIST_LINKLIST_H


