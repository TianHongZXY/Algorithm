//
// Created by TianHongZXY on 2020/4/17.
//

#ifndef ALGORITHM_CH07_H
#define ALGORITHM_CH07_H
typedef char VerterType;
typedef int EdgeType;
const int MAXVEX = 100;
const int INFINITY = 65535;

// 邻接矩阵
typedef struct {
    VerterType vexs[MAXVEX];
    EdgeType arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
}MGraph;

void CreateMGraph(MGraph *G);

// 邻接表
typedef struct EdgeNode{ // 图上的某条边ab
    int adjvex; // 点b在图中对应的顶点的下标
    EdgeType weight; // 点a到点b的路径权值
    struct EdgeNode *next; // 指向点a的另一个邻接点
}EdgeNode;

typedef struct VertexNode{ // 图上的点a
    VerterType data; // 点a存储的信息
    EdgeNode *firstedge; // 点a的边表头指针
}VertexNode;

typedef struct{ // 整个图的邻接表
    VertexNode adjList[MAXVEX]; // 图上所有点
    int numVertexes, numEdges; // 图的点、边总数
}GraphAdjList;

void CreateALGraph(GraphAdjList *G);




#endif //ALGORITHM_CH07_H
