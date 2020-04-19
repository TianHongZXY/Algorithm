//
// Created by TianHongZXY on 2020/4/17.
//

#ifndef ALGORITHM_十字链表_H
#define ALGORITHM_十字链表_H
typedef char VerterType;
typedef int EdgeType;
const int MAXVEX = 100;
const int INFINITY = 65535;
// 十字链表
typedef struct EdgeNode{ // 图上某条边ab
    int headvex, tailvex; // 该条边的头尾
    EdgeType weight;
    struct EdgeNode *headlink, *taillink; // 两个链表，分别保存与a相连，且以a为头或以a为尾的所有点b
}EdgeNode;

typedef struct VertexNode{
    VerterType data;
    EdgeNode *firstin;
    EdgeNode *firstout;
}VertexNode;

typedef struct{ // 整个图的邻接表
    VertexNode adjList[MAXVEX]; // 图上所有点
    int numVertexes, numEdges; // 图的点、边总数
}GraphAdjList;
void CreateALGraph(GraphAdjList *G);
#endif //ALGORITHM_十字链表_H
