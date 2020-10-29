#include <iostream>
#include <time.h>


void getNext(int *next, char *str);
int KMP(int *next, char* searchStr, char* targetStr);
int BF(char* searchStr, char* targetStr);

int main() {
    char searchStr[100], targetStr[100];

    std::cout << "请输入文本：\n";
    std::cin.getline(searchStr, 100);
    std::cout << "请输入搜索字符串：\n";
    std::cin.getline(targetStr, 100);

    int *next = new int[strlen(targetStr)];

    clock_t begin, end;
    begin = clock();
    getNext(next, targetStr);
    std::cout << "KMP:" << KMP(next, searchStr, targetStr);
    end = clock();
    std::cout << ' ' << double(end - begin) / CLOCKS_PER_SEC * 1000 << "ms\n";

    begin = clock();
    std::cout << "BF:" << BF(searchStr, targetStr);
    end = clock();
    std::cout << ' ' << double(end - begin) / CLOCKS_PER_SEC * 1000 << "ms\n";
    return 0;
}

void getNext(int *next, char *str) {
    int nextValue = -1;

    next[0] = -1;
    for(int i = 1; str[i];) {
        if((nextValue == -1) || (str[nextValue] == str[i])) {
            i++;
            nextValue++;
            next[i] = nextValue;
        } else {
            nextValue = next[nextValue];
        }
    }
}

int KMP(int *next, char* searchStr, char* targetStr) {
    int sLen = strlen(searchStr);
    int tLen = strlen(targetStr);
    for (int i = 0; sLen - i >= tLen; i++) {
        if (searchStr[i] == targetStr[0]) {
            i++;
            for (int j = 1; j < tLen;) {
                if (sLen - i < tLen - j) {
                    break;
                }

                if (searchStr[i] == targetStr[j]) {
                    i++;
                    j++;
                } else {
                    j = next[j];
                    if (j == -1) {
                        break;
                    }
                }

                if (j == tLen) {
                    return i - tLen;
                }
            }
        }
    }

    return -1;
}

int BF(char* searchStr, char* targetStr) {
    int sLen = strlen(searchStr),
        tLen = strlen(targetStr);

    for(int i = 0; sLen- i >= tLen; i++) {
        if(searchStr[i] == targetStr[0]) {
            for(int j = 1; j < tLen; j++) {
                if((searchStr[i + j]) != targetStr[j]) {
                    break;
                }

                if(j == tLen - 1) {
                    return i;
                }
            }
        }
    }

    return -1;
}
