#include "LinkList.h"
#include <iostream>
#include <sstream>
template<class T>
LinkList<T>::LinkList() {
    head = new Node<T>;
    head->next = nullptr;
}

template<class T>
LinkList<T>::LinkList(T* items, int len) {
    head = new Node<T>;

    Node<T>* currentNode = head;

    for (int i = 0; i < len; i++) {
        currentNode->next = new Node<T>;
        currentNode->next->element = items[i];
        currentNode = currentNode->next;
    }

    currentNode->next = nullptr;
}

template<class T>
LinkList<T>::~LinkList() {
    while (head->next != nullptr) {
        Node<T>* deleteNode = head->next;
        head->next = head->next->next;
        delete deleteNode;
    }
}

template<class T>
int LinkList<T>::Length() const {
    Node<T> *currentNode = head->next;

    int count = 0;
    while(currentNode != nullptr) {
        count++;
        currentNode = currentNode->next;
    }

    return count;
}

template<class T>
T LinkList<T>::Get(int index) const {
    if(index < 0) {
        std::ostringstream s;
        s << index << "<0,下标必须>0\n";
        throw s.str();
    }

    int count = -1;
    Node<T>* currentNode = head;

    while (count != index) {
        if(currentNode == nullptr) {
            std::ostringstream s;
            s << index << "超过最大长度" << count << '\n';
            throw s.str();
        }
        currentNode = currentNode->next;
        count++;
    }



    return currentNode->element;
}

template<class T>
int LinkList<T>::Locate(T item) const {
    int position = -1;
    Node<T>* currentNode = head;

    int count = 0;
    while (currentNode->next != nullptr) {
        if (currentNode->next->element == item) {
            position = count;
            break;
        }
        count++;
        currentNode = currentNode->next;
    }

    return position;
}

template<class T>
void LinkList<T>::Insert(T item, int index) {
    if(index < 0) {
        std::ostringstream s;
        s << index << "<0,下标必须>0\n";
        throw s.str();
    }

    Node<T>* currentNode = head;
    Node<T>* insertNode = new Node<T>;
    insertNode->element = item;

    for (int i = -1; i < index - 1; i++) {
        if(currentNode == nullptr) {
            std::ostringstream s;
            s << index << "超过最大长度" << i << '\n';
            throw s.str();
        }
        currentNode = currentNode->next;
    }

    insertNode->next = currentNode->next;
    currentNode->next = insertNode;

}

template<class T>
T LinkList<T>::Delete(int index) {
    if(index < 0) {
        std::ostringstream s;
        s << index << "<0,下标必须>0\n";
        throw s.str();
    }

    Node<T>* currentNode = head;
    Node<T>* deleteNode;
    T deleteElement;

    for (int i = -1; i < index - 1; i++) {
        if(currentNode->next == nullptr) {
            std::ostringstream s;
            s << index << "超过最大长度" << i + 1 << '\n';
            throw s.str();
        }
        currentNode = currentNode->next;
    }

    deleteElement = currentNode->next->element;
    deleteNode = currentNode->next;
    currentNode->next = deleteNode->next;
    delete deleteNode;

    return deleteElement;
}

template<class T>
void LinkList<T>::PrintList() const {
    Node<T>* currentNode = head;
    int count = 0;
    while (currentNode->next != nullptr) {
        std::cout << currentNode->next->element << ' ';
        if (!(++count % 8)) {
            std::cout << '\n';
        }
        currentNode = currentNode->next;
    }
    std::cout << '\n';
}

template<class T>
void LinkList<T>::Merge(LinkList<T> &l) {   //默认链表有序
    Node<T> *currentNode = head->next;
    Node<T> *targetNode = l.head->next;

    int index = 0;

    while(currentNode != nullptr && targetNode != nullptr) {
        while(targetNode != nullptr && currentNode->element >= targetNode->element) {
            Insert(targetNode->element, index++);
            targetNode = targetNode->next;
        }
        while(currentNode != nullptr && targetNode != nullptr && currentNode->element < targetNode->element) {
            index++;
            currentNode = currentNode->next;
        }
    }

    while(targetNode != nullptr) {
        Insert(index++, targetNode->element);
        targetNode = targetNode->next;
    }
}

