//
// Created by 朱亦宇 on 2020/9/30.
//

#ifndef CALCULATE_NEW_CALCULATE_H
#define CALCULATE_NEW_CALCULATE_H
#include <stack>
#include <deque>
#include <queue>

class Calculate {
private:
    std::stack<std::string> *oper; //符号栈
    std::stack<std::string> *last_cal; //最终计算栈
    std::queue<std::string> *first_cal; //初始后缀运算栈

    double Docal(); //对后缀运算栈进行计算
    double EasyCal(double num1, double num2, char oper); //基础四则运算
    std::string *GetNum(std::string::iterator &it);
public:
    Calculate(std::string s);

};


#endif //CALCULATE_NEW_CALCULATE_H
