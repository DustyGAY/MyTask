#include <iostream>
#include "HuffmanTree.h"

int main() {
    freopen("test.txt", "r", stdin);
    std::string s;
    std::cin >> s;
    HuffmanTree *h = new HuffmanTree(s);
    std::cout << "编码:";
    std::cout << h->out();
    return 0;
}
