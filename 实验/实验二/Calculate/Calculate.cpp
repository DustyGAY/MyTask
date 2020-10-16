//
// Created by 朱亦宇 on 2020/9/30.
//

#include <string>
#include <sstream>
#include <iostream>
#include "Calculate.h"

Calculate::Calculate(std::string s) {
    oper = new std::stack<std::string>;
    last_cal = new std::stack<std::string>;
    first_cal = new std::queue<std::string>;
    for (std::string::iterator it = s.begin(); it != s.end(); it++) {
        if (*it == ' ') {     //跳过空格
            continue;
        }

        std::string *s;
        s = GetNum(it);

        if (s->front() <= '9' && s->front() >= '0') {
            first_cal->push(*s);  //若为数字直接进入后缀运算队列
//            if (!(oper->empty() || oper->top().front() == '(')) {
//                first_cal->push_front(oper->top()); //若符号栈不为空并且顶部不为左括号，则将符号栈顶部符号压入后缀运算队列
//                oper->pop();
//                if(!oper->empty() && (first_cal->front().front() == '*' || first_cal->front().front() == '/') && (oper->top().front() == '+' || oper->top().front() == '-')) {
//                    first_cal->push_front(oper->top());
//                    oper->pop();
//                }
//            }
        } else {
            if (s->front() == ')') {
                while (oper->top().front() != '(') { //若为又括号，则将所有的括号前的符号压入后缀运算队列
                    first_cal->push(oper->top());
                    oper->pop();
                }
                oper->pop();
//                first_cal->push_front(")");
//                first_cal->push_front(oper->top());
//                oper->pop();
            } else {
                if(*it == '*' || *it == '/') {
                    if(oper->empty() || oper->top().front() == '+' || oper->top().front() == '-' || oper->top().front() == '(') {
                        oper->push(*s);
                    } else {
                        while(!oper->empty() && oper->top().front() != '(' && oper->top().front() != '+' && oper->top().front() != '-') {
                            if(oper->top().front() == '*' || oper->top().front() == '/') {
                                first_cal->push(oper->top());
                                oper->pop();
                            }
                        }
                        oper->push(*s);
                    }
                } else {
                    if(*it == '+' || *it == '-') {
                        while(!oper->empty() && oper->top().front() != '(') {
                            first_cal->push(oper->top());
                            oper->pop();
                        }
                        oper->push(*s);
                    } else {
                        if(*it == '(') {
                            oper->push(*s);
                        }
                    }
                }
            }
        }
        delete s;
    }

    while(!oper->empty()){  //全部压入后缀运算队列
        first_cal->push(oper->top());
        oper->pop();
    }

    delete oper;

    std::cout << Docal();

    delete first_cal;
    delete last_cal;
}

double Calculate::Docal() {
    std::stringstream s;
    while(!first_cal->empty()){
        if(first_cal->front().front() >= '0' && first_cal->front().front() <= '9') {
            last_cal->push(first_cal->front());
        } else {
            double num1, num2;
            s << last_cal->top();
            s >> num2;
            last_cal->pop();
            s.clear();
            s << last_cal->top();
            s >> num1;
            last_cal->pop();
            s.clear();
            s << EasyCal(num1, num2, first_cal->front().front());
            std::string tempStr;
            s >> tempStr;
            last_cal->push(tempStr);
            s.clear();
        }
        first_cal->pop();
    }
    double res;
    s << last_cal->top();
    s >> res;
    return res;
}

std::string *Calculate::GetNum(std::basic_string<char, std::char_traits<char>, std::allocator<char>>::iterator &it) {
    std::string *s = new std::string;
    bool flag = 0;  //判断字符串为符号或数字
    if (*it <= '9' && *it >= '0')
        flag = 1;

    if (!flag) {  //如果为字符，就输入一个
        s->push_back(*it);
    } else {   //如果为字符，持续输入直到下一个字符为空格或符号
        while (*it <= '9' && *it >= '0') {
            s->push_back(*it++);
        }
        it--;
    }

    return s;
}

double Calculate::EasyCal(double num1, double num2, char oper) {
    double res;
    switch (oper) {
        case '+':
            res = num1 + num2;
            break;
        case '-':
            res = num1 - num2;
            break;
        case '*':
            res = num1 * num2;
            break;
        case '/':
            res = num1 / num2;
            break;
        default:
            break;
    }
    return res;
}
