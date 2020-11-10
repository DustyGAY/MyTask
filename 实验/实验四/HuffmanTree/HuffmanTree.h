//
// Created by 基尘 on 2020/10/22.
//

#ifndef HUFFMANTREE_HUFFMANTREE_H
#define HUFFMANTREE_HUFFMANTREE_H
#include "HuffmanTreeNode.h"
#include <set>
#include <map>
#include <queue>

class HuffmanTree{
private:
    std::string res;
    std::string code;
    std::map<char, std::string> codeSet;
    std::map<std::string, char> setCode;
    HuffmanTreeNode *root;
    HuffmanTreeNode *merge(HuffmanTreeNode *h1, HuffmanTreeNode *h2);
    void DFS(HuffmanTreeNode *root);
    void deleteTree(HuffmanTreeNode *root);
public:
    HuffmanTree(std::string &s);
    std::string out();
};


#endif //HUFFMANTREE_HUFFMANTREE_H
