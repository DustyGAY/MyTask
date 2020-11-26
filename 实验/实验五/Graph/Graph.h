//
// Created by 基尘 on 2020/11/25.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

struct Edge {
    char data;
    int index;
    Edge *next;
};

struct Vertex {
    char data;
    Edge *first;
};

class Graph {
private:
    bool isVisited[10];
    Vertex vertex[10];
    int vertexNum;
    int edgeNum;
    void DFS(Vertex *node);
public:
    void BFS();
    void DFS();
    Graph(int vNum, int eNum);
};


#endif //GRAPH_GRAPH_H
