//
// Created by 基尘 on 2020/10/27.
//

#include "String.h"
#include <cctype>
String::String(char *str, int len) {
    size = len;
    length = len;
    this->str = new char[length];
    for(int i = 0; i < length; i++) {
        this->str[i] = str[i];
    }
}

String::~String() {
    delete str;
}

int String::countNum() {
    int count = 0;
    for(int i = 0; i < length; i++) {
        if(!isalnum(str[i])) {  //取巧，统计符号
            count++;
            while(!isalnum(str[++i]) && i < length);
        }
    }
    return count;
}
