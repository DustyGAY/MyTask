//
// Created by 基尘 on 2020/10/16.
//

#ifndef YANGHUITRIANGLE_LINKQUEUE_H
#define YANGHUITRIANGLE_LINKQUEUE_H
#include "Node.h"

class LinkQueue {
private:
    Node *frontPos;
    Node *rearPos;
public:
    LinkQueue();
    ~LinkQueue();
    void push(int item);
    int pop();
    int front();
    int size();
};


#endif //YANGHUITRIANGLE_LINKQUEUE_H
