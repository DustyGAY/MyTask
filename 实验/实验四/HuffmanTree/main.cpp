#include <iostream>
#include "HuffmanTree.h"

int main() {
    std::string s;
    std::cin >> s;
    HuffmanTree *h = new HuffmanTree(s);
    std::cout << "编码:";
    std::cout << h->out();
    return 0;
}
