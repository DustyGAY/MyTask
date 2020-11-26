#include <iostream>
#include "Graph.h"

int main() {
//    freopen("test.txt", "r", stdin);
    Graph g(5, 5);
    printf("DFS:");
    g.DFS();
    printf("BFS:");
    g.BFS();
    return 0;
}
