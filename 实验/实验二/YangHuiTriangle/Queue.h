//
// Created by 基尘 on 2020/10/16.
//

#ifndef YANGHUITRIANGLE_QUEUE_H
#define YANGHUITRIANGLE_QUEUE_H
const int MAXQUEUESIZE = 1000;

class Queue {
private:
    int data[MAXQUEUESIZE];
    int frontPos;
    int rearPos;
public:
    Queue();
    void push(int item);
    int pop();
    int front();
    int size();
};


#endif //YANGHUITRIANGLE_QUEUE_H
