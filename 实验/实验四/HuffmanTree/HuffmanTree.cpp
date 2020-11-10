//
// Created by 基尘 on 2020/10/22.
//

#include <string>
#include <iostream>
#include "HuffmanTree.h"

class cmp {
public:
    bool operator () (HuffmanTreeNode *h1, HuffmanTreeNode *h2) {
        if(h1->weight != h2->weight) {
            return h1->weight < h2->weight;
        } else if(h1->element != h2->element){
            return h1->element < h2->element;
        } else {
            return h1->leftChild < h2->leftChild;
        }
    }
};

HuffmanTree::HuffmanTree(std::string &s) {
    int count[128];
    memset(count, 0, sizeof(count));

    for(auto ch : s) {
        count[ch]++;
    }

    std::set<HuffmanTreeNode*, cmp> tree;

    for(int i = 0; i < 128; i++) {
        if(count[i]) {
            HuffmanTreeNode *tempHuffmanTreeNode = new HuffmanTreeNode;
            tempHuffmanTreeNode->weight = count[i];
            tempHuffmanTreeNode->element = i;
            tempHuffmanTreeNode->rightChild = tempHuffmanTreeNode->leftChild = nullptr;
            tree.insert(tempHuffmanTreeNode);
        }
    }

//    for(auto x : tree) {
//        std::cout << x->element << ' ' <<  x->weight << '\n';
//    }

    while(tree.size() != 1) {
        HuffmanTreeNode *h1 = *tree.begin();
        tree.erase(tree.begin());
        HuffmanTreeNode *h2 = *tree.begin();
        tree.erase(tree.begin());
        tree.insert(merge(h1, h2));
    }

    root = *tree.begin();

    DFS(root);



    for(auto x : codeSet) {
        std::cout << x.first << ' ' << x.second << '\n';
    }

    for(auto it : s) {
        res += codeSet[it];
    }

    //解码
    std::cout << "解码:";
    for(auto x : codeSet) {
        setCode[x.second] = x.first;
    }

    std::string tempString;
    for(auto x : res) {
        tempString.push_back(x);
        auto pos = setCode.find(tempString);
        if(pos != setCode.end()) {
            std::cout << pos->second;
            tempString.clear();
        }
    }
    std::cout << '\n';
}

HuffmanTreeNode *HuffmanTree::merge(HuffmanTreeNode *h1, HuffmanTreeNode *h2) {
    HuffmanTreeNode *res = new HuffmanTreeNode;
    res->leftChild = h1;
    res->rightChild = h2;
    res->weight = h1->weight + h2->weight;
    res->element = 0;
    return res;
}

void HuffmanTree::DFS(HuffmanTreeNode *root) {
    if(root->element) {
        codeSet[root->element] = code;
        return;
    }

    code.push_back('0');
    DFS(root->leftChild);
    code.pop_back();

    code.push_back('1');
    DFS(root->rightChild);
    code.pop_back();
}

std::string HuffmanTree::out() {
    return res;
}

void HuffmanTree::deleteTree(HuffmanTreeNode *root) {
    if(root == nullptr) {
        return;
    }

    deleteTree(root->leftChild);
    deleteTree(root->rightChild);
    delete root;
}
