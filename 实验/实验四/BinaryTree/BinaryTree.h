//
// Created by 基尘 on 2020/11/11.
//

#ifndef BINARYTREE_BINARYTREE_H
#define BINARYTREE_BINARYTREE_H
#include "BinaryTreeNode.h"
#include <iostream>

template <class T>
class BinaryTree {
private:
    int leaveCount;
    BinaryTreeNode<T> *root;
    static void print(BinaryTreeNode<T> *currentNode) {std::cout << currentNode << ' ';}
    static void isLeave(BinaryTreeNode<T> *currentNode) {if(currentNode)if(!currentNode->leftChild && !currentNode->rightChild) leaveCount++;}
    static void dispose(BinaryTree<T> *currentNode) {delete currentNode;}
    static void *visit(BinaryTreeNode<T> *currentNode);
    static void preOrder(BinaryTreeNode<T> *currentNode);
    static void inOrder(BinaryTreeNode<T> *currentNode);
    static void postOrder(BinaryTreeNode<T> *currentNode);
public:
    void preOrder(void (*theVisit)(BinaryTree<T> *currentNode)){visit = theVisit; preOrder(root)};
    void inOrder(void (*theVisit)(BinaryTree<T> *currentNode)){visit = theVisit; inOrder(root)};
    void postOrder(void (*theVisit)(BinaryTree<T> *currentNode)){visit = theVisit; postOrder(root)};
    ~BinaryTree() {postOrder(dispose); root = nullptr;}
    BinaryTree(BinaryTreeNode *root) {this->root = root};
    void prePrint() {preOrder(print);}
    void inPrint() {inOrder(print);}
    void postPrint() {postOrder(print);}

    int countLeave() {leaveCount = 0; preOrder(isLeave); return leaveCount;};
 }


#endif //BINARYTREE_BINARYTREE_H
