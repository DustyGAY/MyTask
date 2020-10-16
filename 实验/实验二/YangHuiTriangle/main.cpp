#include <iostream>
#include "Queue.h"
#include <sstream>
#include "LinkQueue.h"
void yHTriangle(int line);

int main() {
    std::cout << "请输入杨辉三角行数：\n";
    int line;
    std::cin >> line;
    try {
        yHTriangle(line);
    } catch (std::string s) {
        std::cout << s;
    }
    return 0;
}

void yHTriangle(int line) {
    int choose = 0;
    std::cout << "请选择数据结构：\n1.循环队列\n2.链式队列\n";
    std::cin >> choose;
    if(choose == 1) {
        if(line == 0) {
            return;
        }

        if(line < 0) {
            std::ostringstream s;
            s << line << "小于0，杨辉三角行数需大于等于0\n";
            throw s.str();
        }

        auto *preLine = new Queue; //初始化
        preLine->push(0);
        preLine->push(1);
        preLine->push(0);

        for(int i = 0; i < line; i++) {
            int size = preLine->size();

            preLine->push(0);

            for(int j = 0; j < size - 1; j++){
                int currentElement = preLine->pop();
                preLine->push(currentElement + preLine->front());

                if(currentElement < 0) {
                    std::ostringstream s;
                    s << "数据超出int上限\n";
                    throw s.str();
                }

                if(currentElement) {
                    std::cout << currentElement << ' ';
                }


            }

            preLine->pop();
            preLine->push(0);

            std::cout << '\n';

        }
        delete preLine;
    } else
        if(choose == 2) {
            if(line == 0) {
                return;
            }

            if(line < 0) {
                std::ostringstream s;
                s << line << "小于0，杨辉三角行数需大于等于0\n";
                throw s.str();
            }

            auto *preLine = new LinkQueue; //初始化
            preLine->push(0);
            preLine->push(1);
            preLine->push(0);

            for(int i = 0; i < line; i++) {
                int size = preLine->size();

                preLine->push(0);

                for (int j = 0; j < size - 1; j++) {
                    int currentElement = preLine->pop();
                    preLine->push(currentElement + preLine->front());

                    if (currentElement) {
                        std::cout << currentElement << ' ';
                    }

                    if(currentElement < 0) {
                        std::ostringstream s;
                        s << "\n数据超出int上限\n";
                        throw s.str();
                    }

                }

                preLine->pop();
                preLine->push(0);

                std::cout << '\n';

            }

            delete preLine;
        }

}