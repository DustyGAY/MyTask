//
// Created by 基尘 on 2020/10/15.
//

#include "SeqStack.h"
#include <sstream>

SeqStack::SeqStack() {
    top = -1;
}

void SeqStack::push(char item) {
    if(top == MAXSTACKSIZE - 1) {
        std::ostringstream s;
        s << "栈满\n";
        throw s.str();
    }

    data[++top] = item;
}

char SeqStack::pop() {
    if(top == -1) {
        std::ostringstream s;
        s << "栈空\n";
        throw s.str();
    }

    return data[top--];
}

bool SeqStack::isEmpty() {
    return (top == -1);
}
