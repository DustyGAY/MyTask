//
// Created by 基尘 on 2020/11/25.
//

#include "Graph.h"
#include <iostream>

Graph::Graph(int vNum, int eNum) {
    vertexNum = vNum;
    edgeNum = eNum;

    memset(isVisited, 0, sizeof(isVisited));

    for(int i = 0; i < vNum; i++) {
        std::cout << "请输入第" << i + 1 << "个结点信息:\n值:";
        std::cin >> vertex[i].data;
        vertex[i].first = nullptr;
    }

    for(int i = 0; i < eNum; i++) {
        std::cout << "请输入第" << i + 1 << "条边信息:\n起点:";
        int begin, end;
        std::cin >> begin;
        std::cout << "终点:";
        std::cin >> end;
        Edge *tempEdge = new Edge;
        tempEdge->index = end - 1;
        tempEdge->data = vertex[tempEdge->index].data;

        tempEdge->next = vertex[begin - 1].first;
        vertex[begin - 1].first = tempEdge;
    }
}

void Graph::DFS(Vertex *node) {
    if(node == nullptr) {
        return;
    }

    Edge *currentNode = node->first;
    while(currentNode != nullptr) {
        if(!isVisited[currentNode->index]) {
            std::cout << currentNode->data << ' ';
            isVisited[currentNode->index] = 1;
            DFS(&vertex[currentNode->index]);
        }
        currentNode = currentNode->next;
    }
}

void Graph::DFS() {
    for(int i = 0; i < vertexNum; i++) {
        if(!isVisited[i]) {
            printf("%c ", vertex[i].data);
            isVisited[i] = 1;
        }
        DFS(&vertex[i]);
    }
    std::cout << '\n';
}

void Graph::BFS() {
    for(int i = 0; i < vertexNum; i++) {
        printf("%c ", vertex[i].data);
    }
    printf("\n");
}
