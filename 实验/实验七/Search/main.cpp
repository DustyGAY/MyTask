#include <iostream>
#include <time.h>

const int MAXSIZE = 1000000;
int testNum[MAXSIZE];
int targetNum = 66666;

const int HASH_VALUE = 100007;
struct Node {
    int index;
    int element;
    Node *next;
};

clock_t begin, end;

int seqSearch();
int binarySearch(int left, int right);
int hashSearch();

Node *hashTable = new Node[HASH_VALUE];

int main() {
    srand(time(nullptr));

    for(int i = 0; i < MAXSIZE; i++) {
        testNum[i] = rand() % MAXSIZE;
    }
    std::sort(testNum, testNum + MAXSIZE);

    begin = clock();
    printf("顺序:%d \n", seqSearch());
    end = clock();
    printf("耗时:%lf ms\n", double(end - begin) / CLOCKS_PER_SEC * 1000);

    begin = clock();
    printf("二分:%d \n", binarySearch(0, MAXSIZE - 1));
    end = clock();
    printf("耗时:%lf ms\n", double(end - begin) / CLOCKS_PER_SEC * 1000);

    for(int i = 0; i < HASH_VALUE; i++) {
        hashTable[i].index = -1;
        hashTable[i].element = -1;
        hashTable->next = nullptr;
    }

    for (int i = 0; i < MAXSIZE; i++) {
        Node *currentNode = new Node;
        currentNode->index = i;
        currentNode->element = testNum[i];
        currentNode->next = hashTable[testNum[i] % HASH_VALUE].next;
        hashTable[testNum[i] % HASH_VALUE].next = currentNode;
    }

    begin = clock();
    printf("散列:%d \n", hashSearch());
    end = clock();
    printf("耗时:%lf ms\n", double(end - begin) / CLOCKS_PER_SEC * 1000);

    return 0;
}

int seqSearch() {
    for(int i = 0; i < MAXSIZE; i++) {
        if(testNum[i] == targetNum) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int left, int right) {
    int mid = (left + right) / 2;

    if(left > right) {
        return -1;
    }

    if(testNum[mid] == targetNum) {
        while (testNum[mid - 1] == targetNum) {
            --mid;
        }
        return mid;
    }

    if(testNum[mid] < targetNum) {
        return binarySearch(mid + 1, right);
    } else {
        return binarySearch(left, mid - 1);
    }

}

int hashSearch() {
    int hashValue = targetNum % HASH_VALUE;

    int pos = 0x3f3f3f3f;

    Node *currentNode = hashTable[hashValue].next;
    while (currentNode != nullptr) {
        if(currentNode->element == targetNum) {
            pos = std::min(currentNode->index, pos);
        }
        currentNode = currentNode->next;
    }

    return (pos >= MAXSIZE ? -1 : pos);
}
