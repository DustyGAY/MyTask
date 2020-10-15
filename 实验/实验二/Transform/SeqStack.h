//
// Created by 基尘 on 2020/10/15.
//

#ifndef TRANSFORM_SEQSTACK_H
#define TRANSFORM_SEQSTACK_H

const int MAXSTACKSIZE = 100;

class SeqStack {
private:
    char data[MAXSTACKSIZE];
    int top;
public:
    SeqStack();
    void push(char item);
    char pop();
    bool isEmpty();
};


#endif //TRANSFORM_SEQSTACK_H
