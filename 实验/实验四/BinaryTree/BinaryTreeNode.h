//
// Created by 基尘 on 2020/11/11.
//

#ifndef BINARYTREE_BINARYTREENODE_H
#define BINARYTREE_BINARYTREENODE_H

template <class T>
struct BinaryTreeNode {
    T element;
    BinaryTreeNode* leftChild;
    BinaryTreeNode* rightChild;
};

#endif //BINARYTREE_BINARYTREENODE_H
