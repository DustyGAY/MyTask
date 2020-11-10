//
// Created by 基尘 on 2020/10/22.
//

#ifndef HUFFMANTREE_HUFFMANTREENODE_H
#define HUFFMANTREE_HUFFMANTREENODE_H

struct HuffmanTreeNode {
    int weight;
    char element;
    HuffmanTreeNode *leftChild;
    HuffmanTreeNode *rightChild;
//    friend bool operator < (HuffmanTreeNode &h1, HuffmanTreeNode &h2) {
//        return h1.weight < h2.weight;
//    }
};

#endif //HUFFMANTREE_HUFFMANTREENODE_H
