#include <iostream>
#include "Calculate.h"

int main() {
    std::string s;
    getline(std::cin, s);
    Calculate *cal = new Calculate(s);
    delete cal;
    return 0;
}




