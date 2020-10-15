#include <iostream>
#include "SeqStack.h"
#include "LinkStack.h"

int main() {
    std::cout << "请输入目标进制:";
    int base;
    std::cin >> base;

    std::cout << "请输入待转换的数:";
    int number;
    std::cin >> number;

    int choose;
    std::cout << "请选择数据结构：\n1.顺序栈\n2.链栈\n";
    std::cin >> choose;

    if(choose == 1) {
        SeqStack *res = new SeqStack();

        if(!number) {   //数为0情况
            res->push('0');
        }

        bool isNegative = 0;
        if(number < 0) {    //负数情况
            number = abs(number);
            isNegative = 1;
        }

        while(number) {
            int tempNum;
            tempNum = number % base;
            number /= base;

            if(tempNum < 10) {
                res->push(tempNum + '0');
            } else {
                res->push(tempNum + 'A' - 10);
            }
        }

        if(isNegative) {
            res->push('-');
        }

        while(!res->isEmpty()) {
            std::cout << res->pop();
        }
        delete res;
    } else {
        LinkStack *res = new LinkStack;

        if(!number) {   //数为0情况
            res->push('0');
        }

        bool isNegative = 0;
        if(number < 0) {    //负数情况
            number = abs(number);
            isNegative = 1;
        }

        while(number) {
            int tempNum;
            tempNum = number % base;
            number /= base;

            if(tempNum < 10) {
                res->push(tempNum + '0');
            } else {
                res->push(tempNum + 'A' - 10);
            }
        }

        if(isNegative) {
            res->push('-');
        }

        while(!res->isEmpty()) {
            std::cout << res->pop();
        }
        delete res;
    }


    return 0;
}
