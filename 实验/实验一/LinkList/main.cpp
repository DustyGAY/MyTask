#include <iostream>
#include "LinkList.h"
#include "LinkList.cpp"

int main() {
    int testNumber[] = { 1, 3, 5, 4, 2 };

    LinkList<int>* l1 = new LinkList<int>(testNumber, 5);

    std::cout << "l1:";
    l1->PrintList();
    std::cout << '\n';

    std::cout << "l1长度:" << l1->Length() << '\n';
    std::cout << '\n';

    std::cout << "删除下标为2的元素:";
    try {
        std::cout << l1->Delete(2) << '\n';
        std::cout << "l1:";
        l1->PrintList();
    } catch (std::string s) {
        std::cout << s;
    }
    std::cout << '\n';

    std::cout << "删除下标为6的元素:";
    try {
        std::cout << l1->Delete(6) << '\n';
        std::cout << "l1:";
        l1->PrintList();
    } catch (std::string s) {
        std::cout << s;
    }
    std::cout << '\n';

    std::cout << "删除下标为-1的元素:";
    try {
        std::cout << l1->Delete(-1) << '\n';
        std::cout << "l1:";
        l1->PrintList();
    } catch (std::string s) {
        std::cout << s;
    }
    std::cout << '\n';


    std::cout << "获取下标为3的元素:";
    try {
        std::cout << l1->Get(3) << '\n';
    } catch (std::string s) {
        std::cout << s;
    }
    std::cout << '\n';

    std::cout << "获取下标为7的元素:";
    try {
        std::cout << l1->Get(7) << '\n';
    } catch (std::string s) {
        std::cout << s;
    }
    std::cout << '\n';

    std::cout << "获取下标为-1的元素:";
    try {
        std::cout << l1->Get(-1) << '\n';
    } catch (std::string s) {
        std::cout << s;
    }
    std::cout << '\n';

    std::cout << "元素2的位置为:";
    {
        int pos = l1->Locate(2);
        if(pos == -1) {
            std::cout << "不存在\n";
        } else {
            std::cout << pos << '\n';
        }
    };
    std::cout << '\n';

    std::cout << "元素5的位置为:";
    {
        int pos = l1->Locate(5);
        if(pos == -1) {
            std::cout << "不存在\n";
        } else {
            std::cout << pos << '\n';
        }
    };
    std::cout << '\n';

    std::cout << "在位置9插入元素7\n";
    try {
        l1->Insert(7, 9);
        std::cout << "l1:";
        l1->PrintList();
    } catch (std::string s) {
        std::cout << s;
    }
    std::cout << '\n';

    std::cout << "在位置2插入元素7\n";
    try {
        l1->Insert(7, 2);
        std::cout << "l1:";
        l1->PrintList();
    } catch (std::string s) {
        std::cout << s;
    }
    std::cout << '\n';

    std::cout << "在位置-5插入元素7\n";
    try {
        l1->Insert(7, -5);
        std::cout << "l1:";
        l1->PrintList();
    } catch (std::string s) {
        std::cout << s;
    }
    std::cout << '\n';
    delete l1;


    int testNumber2[] = { 1, 3, 5, 6, 7, 9 };
    int testNumber3[] = { 2, 4, 5, 8};

    LinkList<int>* l2 = new LinkList<int>(testNumber2, 6);
    LinkList<int>* l3 = new LinkList<int>(testNumber3, 4);

    std::cout << "l2:";
    l2->PrintList();
    std::cout << "l3:";
    l3->PrintList();

    std::cout << "l2, l3合并：";
    l2->Merge(*l3);
    l2->PrintList();
    std::cout << '\n';

    delete l2;
    delete l3;


    int testNumber4[] = { 1, 3, 5, 6, 7, 9 };
    int testNumber5[] = { 2, 4, 5, 8, 10, 11};

    LinkList<int>* l4 = new LinkList<int>(testNumber4, 6);
    LinkList<int>* l5 = new LinkList<int>(testNumber5, 6);

    std::cout << "l4:";
    l4->PrintList();
    std::cout << "l5:";
    l5->PrintList();

    std::cout << "l4, l5合并：";
    l4->Merge(*l5);
    l4->PrintList();

    delete l4;
    delete l5;

    return 0;
}
