//
// Created by 基尘 on 2020/11/11.
//

#include "BinaryTree.h"

template<class T>
void BinaryTree<T>::preOrder(BinaryTreeNode<T> *currentNode) {
    if(currentNode != nullptr) {
        visit(currentNode);
        preOrder(currentNode->leftChild);
        preOrder(currentNode->rightChild);
    }
}

template<class T>
void BinaryTree<T>::inOrder(BinaryTreeNode<T> *currentNode) {
    if(currentNode != nullptr) {
        preOrder(currentNode->leftChild);
        visit(currentNode);
        preOrder(currentNode->rightChild);
    }
}

template<class T>
void BinaryTree<T>::postOrder(BinaryTreeNode<T> *currentNode) {
    if(currentNode != nullptr) {
        preOrder(currentNode->leftChild);
        preOrder(currentNode->rightChild);
        visit(currentNode);
    }
}
