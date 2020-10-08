#include <iostream>
#include "SeqList.h"
#include "SeqList.cpp"

int main() {
    int num[] = {5, 4, 2, 7, 9};

    SeqList<int> *s1 = new SeqList<int>(num, 5),
                 *s2 = new SeqList<int>(num, 5);

    std::cout << "s1: ";
    s1->Print();

    std::cout << "s2: ";
    s2->Print();

    std::cout << "s1插入位置3: \n";
    try {
        s1->Insert(6, 3);
    } catch (std::string s) {
        std::cout << s << '\n';
    }
    s1->Print();
    std::cout << '\n';


    std::cout << "s1插入位置7: \n";
    try {
        s1->Insert(6, 7);
    }
    catch (std::string s) {
        std::cout << s << '\n';
    }
    s1->Print();
    std::cout << '\n';

    std::cout << "s1有序插入3: \n";
    try {
        s1->InsertSort(3);
    } catch (std::string s) {
        std::cout << s << '\n';
    }
    s1->Print();
    std::cout << '\n';

    std::cout << "s1长度: " << s1->GetLength() << '\n';
    std::cout << '\n';

    std::cout << "s1定位数字7: \n下标:";
    std::cout << s1->Locate(7) << '\n';
    std::cout << '\n';

    std::cout << "s1获取下标5: \n下标:";
    try {
        std::cout << s1->Get(5) << '\n';
    } catch (std::string s) {
        std::cout << s << '\n';
    }
    std::cout << '\n';

    std::cout << "s1获取下标9: \n下标:";
    try {
        std::cout << s1->Get(9) << '\n';
    } catch (std::string s) {
        std::cout << s << '\n';
    }
    std::cout << '\n';

    std::cout << "s1删除下标5: \n";
    try {
        std::cout << "删除元素: \n" << s1->Delete(5) << '\n';
    } catch (std::string s) {
        std::cout << s << '\n';
    }
    s1->Print();
    std::cout << '\n';

    std::cout << "s1删除下标8: \n";
    try {
        std::cout << "删除元素: \n" << s1->Delete(8) << '\n';
    } catch (std::string s) {
        std::cout << s << '\n';
    }
    s1->Print();
    std::cout << '\n';

    std::cout << "s1: ";
    s1->Print();
    std::cout << "s2: ";
    s2->Print();

    std::cout << "有序合并s1, s2:\n";
    s1->Union(*s2);
    s1->Print();
    return 0;
}
