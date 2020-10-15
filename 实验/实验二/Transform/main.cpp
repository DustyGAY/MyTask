#include <iostream>
#include <sstream>
#include "SeqStack.h"
#include "LinkStack.h"

int main() {
    try {
        std::ostringstream s;

        std::cout << "请输入目标进制:";
        int base;
        std::cin >> base;
        if(base <= 0) {
            s << "进制需大于0\n";
            throw s.str();
        }

        if(base > 36) {
            s << "进制" << base << "超出算法上限\n";
            throw s.str();
        }

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
        } else
            if(choose == 2) {
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
        } else {
                s << choose << "是错误的选择\n";
                throw s.str();
            }
    } catch (std::string s) {
        std::cout << s;
    }


    return 0;
}
