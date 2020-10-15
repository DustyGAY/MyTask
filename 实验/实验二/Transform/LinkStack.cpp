//
// Created by 基尘 on 2020/10/15.
//

#include "LinkStack.h"
#include <sstream>

LinkStack::LinkStack() {
    top = nullptr;
}

LinkStack::~LinkStack() {
    Node* deleteNode;

    while(top != nullptr) {
        deleteNode = top;
        top = top->next;
        delete deleteNode;
    }
}

void LinkStack::push(char item) {
    Node *targetNode = new Node{item};

    targetNode->next = top;
    top = targetNode;
}

char LinkStack::pop() {
    if(isEmpty()) {
        std::ostringstream s;
        s << "栈为空\n";
        throw s.str();
    }

    Node* deleteNode = top;
    char deleteElement = deleteNode->element;

    top = top->next;
    delete deleteNode;

    return deleteElement;
}

bool LinkStack::isEmpty() {
    return (top == nullptr);
}
