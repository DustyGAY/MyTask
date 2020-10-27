#include <iostream>
#include "String.h"
int main() {
    char str[100];
    std::cin.getline(str, 100);
    String *s = new String(str, strlen(str));
    std::cout << s->countNum();
    delete s;
    return 0;
}
