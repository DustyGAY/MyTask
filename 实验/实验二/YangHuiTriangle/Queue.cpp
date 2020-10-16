//
// Created by 基尘 on 2020/10/16.
//

#include "Queue.h"
#include "sstream"

Queue::Queue() {
    frontPos = MAXQUEUESIZE - 1;
    rearPos = 0;
}

void Queue::push(int item) {
    if(rearPos == frontPos) {
        std::ostringstream s;
        s << "队列已满\n";
        throw s.str();
    }

    data[rearPos++] = item;
    if(rearPos == MAXQUEUESIZE) {
        rearPos = 0;
    }
}

int Queue::pop() {
    if(rearPos - 1 == frontPos || (rearPos == 0 && frontPos == MAXQUEUESIZE)) {
        std::ostringstream s;
        s << "队列空\n";
        throw s.str();
    }

    if(++frontPos == MAXQUEUESIZE) {
        frontPos = 0;
    }

    return data[frontPos];
}

int Queue::front() {
    return data[frontPos + 1];
}

int Queue::size() {
    if(frontPos < rearPos) {
        return rearPos - frontPos - 1;
    } else {
        return MAXQUEUESIZE - 1 - frontPos + rearPos;
    }
}
