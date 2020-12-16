#include <iostream>

int countRes = 0;
int res[10];

struct Edge {
    int weight;
    bool isIn;
};

int main() {
    freopen("test.txt", "r", stdin);
    Edge edge[10][10];
    memset(edge, 0, sizeof(edge));

    std::cout << "结点数：10，名称A-J\n";
    for(int i = 0; i < 20; i++) {
        std::cout << "输入" << i + 1 << "条边信息:\n起点:";
        int begin, end;
        std::cin >> begin;
        std::cout << "终点:\n";
        std::cin >> end;
        if(begin < end) {
            std::swap(begin, end);
        }
        --begin;
        --end;
        std::cout << "权值:\n";
        std::cin >> edge[begin][end].weight;
        edge[begin][end].isIn = 1;
    }

    res[countRes++] = 0;
    for(int i = 1; i < 10; i++) {
        int minEdge = -1;
        int pos;
        for(int j = 0; j < countRes; j++) {
            for(int k = 0; k < j; k++) {
                if(edge[res[j]][k].isIn == 1) {
                    if(edge[res[j]][k].weight < minEdge || minEdge == -1) {
                        minEdge = edge[res[j]][k].weight;
                        pos = k;
                    }
                }
            }
            for(int k = res[j] + 1; k < 10; k++) {
                if(edge[k][res[j]].isIn == 1) {
                    if(edge[k][res[j]].weight < minEdge || minEdge == -1) {
                        minEdge = edge[k][res[j]].weight;
                        pos = k;
                    }
                }
            }
        }
        res[countRes++] = pos;
        for(int k = 0; k < pos; k++) {
            if(edge[pos][k].isIn == 1) {
                for(int j = 0; j < countRes; j++) {
                    if(k == res[j]) {
                        edge[pos][k].isIn = 0;
                    }
                }
            }
        }
        for(int k = pos + 1; k < 10; k++) {
            if(edge[k][pos].isIn == 1) {
                for(int j = 0; j < countRes; j++) {
                    if(k == res[j]) {
                        edge[k][pos].isIn = 0;
                    }
                }
            }
        }
    }

    for(int i = 0; i < 10; i++) {
        std::cout << char(res[i] + 'A');
    }
    return 0;
}
