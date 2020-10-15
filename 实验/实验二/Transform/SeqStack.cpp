//
// Created by 基尘 on 2020/10/15.
//

#include "SeqStack.h"

SeqStack::SeqStack() {
    top = -1;
}

void SeqStack::push(char item) {
    data[++top] = item;
}

char SeqStack::pop() {
    return data[top--];
}

bool SeqStack::isEmpty() {
    return (top == -1?1:0);
}
