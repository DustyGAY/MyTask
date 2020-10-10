//
// Created by 基尘 on 2020/9/29.
//

#ifndef SEQLIST_SEQLIST_H
#define SEQLIST_SEQLIST_H

const int MAXSIZE = 100;

template <class T>
class SeqList {
private:
    T data[MAXSIZE];
    int length;
    void CheckIndex(int index) const;
    void CheckMaxsize(int len) const;
    void Sort();
public:
    SeqList();
    SeqList(T *items, int len);
    SeqList(SeqList<T> &s);
    int GetLength() const;
    T Get(int index) const;
    void Insert(T item, int index);
    T Delete(int index);
    int Locate(T item);
    void Print();
    void InsertSort(T item);
    void Union(SeqList<T> s);
    bool Empty() const;
};

#endif //SEQLIST_SEQLIST_H
