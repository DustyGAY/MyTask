//
// Created by 基尘 on 2020/9/29.
//

#include <algorithm>
#include <sstream>
#include <iostream>
#include "SeqList.h"

template<class T>
SeqList<T>::SeqList() {
    length = 0;
}

template<class T>
SeqList<T>::SeqList(T *items, int len) {
    CheckMaxsize(len);
    length = len;
    std::copy(items, items + len, data);
}

template<class T>
int SeqList<T>::GetLength() const {
    return length;
}

template<class T>
T SeqList<T>::Get(int index) const {
    CheckIndex(index);
    return data[index];
}

template<class T>
void SeqList<T>::Insert(T item, int index) {
    if(index != length)
        CheckIndex(index);

    if(length == MAXSIZE) {
        std::cout << "数组已满\n";
        return;
    }

    std::copy(data + index, data + length, data + index + 1);
    length++;
    data[index] = item;
}

template<class T>
T SeqList<T>::Delete(int index) {
    CheckIndex(index);
    T temp = data[index];
    std::copy(data + index + 1, data + length, data + index);
    length--;
    return temp;
}

template<class T>
int SeqList<T>::Locate(T item) {
    int position = -1;
    for(int i = 0; i < length; i++)
        if(data[i] == item){
            position = i;
            break;
        }
    return position;
}

template<class T>
void SeqList<T>::CheckIndex(int index) const{
    if(index >= length){
        std::ostringstream s;
        s << index << " is out of length = " << length;
        throw s.str();
    }
}

template<class T>
void SeqList<T>::CheckMaxsize(int len) const{
    if(len >= MAXSIZE){
        std::ostringstream s;
        s << len << " is out of MAXSIZE = " << MAXSIZE;
        throw s.str();
    }
}

template<class T>
void SeqList<T>::Print() {
    if(length == 0) {
        std::cout << "Empty List\n";
    } else {
        for(int i = 0; i < length; i++) {
            std::cout << data[i] << ' ';
        }
        std::cout << '\n';
    }
}

template<class T>
void SeqList<T>::InsertSort(T item) {
    if(length == MAXSIZE) {
        std::cout << "数组已满\n";
        return;
    }

    Sort();

    bool isInsert = 0;
    for(int i = 0; i < length; i++) {
        if(item < data[i]) {
            Insert(item, i);
            isInsert = 1;
            break;
        }
    }
    if(!isInsert) {
        Insert(item, length);
    }
}

template<class T>
void SeqList<T>::Union(SeqList<T> s) {
    s.Sort();
    SeqList<T> *tempSeqList = new SeqList<T>(*this);
    tempSeqList->Sort();
    T *p1 = tempSeqList->data;
    T *p2 = s.data;
    T *p3 = this->data;
    while(p1 != tempSeqList->data + tempSeqList->length && p2 != s.data + s.length) {
        if(*p1 < *p2) {
            *p3++ = *p1++;
        } else {
            *p3++ = *p2++;
        }
    }
    if(p1 == tempSeqList->data + tempSeqList->length) {
        while(p2 != s.data + s.length + 1) {
            *p3++ = *p2++;
        }
    } else {
        while(p1 != tempSeqList->data + tempSeqList->length) {
            *p3++ = *p1++;
        }
    }

    this->length += s.length;
}

template<class T>
void SeqList<T>::Sort() {
    std::sort(data, data + length);
}

template<class T>
SeqList<T>::SeqList(SeqList<T> &s) {
    for(int i = 0; i < s.length; i++) {
        this->data[i] = s.data[i];
    }

    this->length = s.length;
}

template<class T>
bool SeqList<T>::Empty() const {
    return length;
}
