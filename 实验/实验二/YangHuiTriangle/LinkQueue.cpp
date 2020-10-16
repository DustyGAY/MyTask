//
// Created by 基尘 on 2020/10/16.
//

#include "LinkQueue.h"
#include <sstream>
LinkQueue::LinkQueue() {
    frontPos = nullptr;
    rearPos = nullptr;
}

LinkQueue::~LinkQueue() {
    Node *deleteNode;

    while(rearPos) {
        deleteNode = frontPos;
        frontPos = frontPos->next;
        delete deleteNode;
    }
}

void LinkQueue::push(int item) {
    Node *insertNode = new Node{item, nullptr};

    if(!frontPos) {
        frontPos = insertNode;
        rearPos = insertNode;
    } else {
        rearPos->next = insertNode;
        rearPos = rearPos->next;
    }

}

int LinkQueue::pop() {
    if(!size()) {
        std::ostringstream s;
        s << "空队列\n";
        throw s.str();
    }

    Node *deleteNode = frontPos;
    int deleteElement = deleteNode->element;

    frontPos = frontPos->next;
    delete deleteNode;

    return deleteElement;
}

int LinkQueue::front() {
    if(!size()) {
        std::ostringstream s;
        s << "空队列\n";
        throw s.str();
    }

    return frontPos->element;
}

int LinkQueue::size() {
    Node *currentNode = frontPos;
    int count = 0;
    while(currentNode != nullptr) {
        ++count;
        currentNode = currentNode->next;
    }
    return count;
}
