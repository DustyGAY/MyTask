//
// Created by 基尘 on 2020/10/15.
//

#ifndef TRANSFORM_LINKSTACK_H
#define TRANSFORM_LINKSTACK_H
#include "Node.h"

class LinkStack {
private:
    Node *top;
public:
    LinkStack();
    ~LinkStack();
    void push(char item);
    char pop();
    bool isEmpty();
};


#endif //TRANSFORM_LINKSTACK_H
