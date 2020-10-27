//
// Created by 基尘 on 2020/10/27.
//

#ifndef COUNTNUM_STRING_H
#define COUNTNUM_STRING_H


class String {
private:
    char *str;
    int size;
    int length;
public:
    String(char *str, int len);
    ~String();
    int countNum();
};


#endif //COUNTNUM_STRING_H
