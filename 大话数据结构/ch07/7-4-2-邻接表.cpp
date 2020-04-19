//
// Created by TianHongZXY on 2020/4/16.
//
#include <cstdio>
typedef char VerterType;
typedef int EdgeType;
const int MAXVEX = 100;

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

void CreateALGraph(GraphAdjList *G){
    int i, j, w;
    printf("输入顶点数和边数：\n");
    scanf("%d%d", &G->numVertexes, &G->numEdges);
    printf("输入每个点的data：\n");
    getchar();
    for(int k = 0; k < G->numVertexes; k++){
        scanf("%c", &G->adjList[k].data);
        G->adjList[k].firstedge = NULL;
        getchar();
    }
    for(int k = 0; k < G->numEdges; k++){
        printf("输入边(vi, vj)的下标i, j和权值w：\n");
        scanf("%d%d%d", &i, &j, &w);
        EdgeNode *e = new EdgeNode;
        e->weight = w;
        e->adjvex = j;
        e->next = G->adjList[i].firstedge; // 链表的头插法，把e的next指向点i的邻接表头
        G->adjList[i].firstedge = e; // 把点i的邻接表头设为e

        // 如果为无向图，再将j指向i
        e = new EdgeNode;
        e->weight = w;
        e->adjvex = i;
        e->next = G->adjList[j].firstedge;
        G->adjList[j].firstedge = e;
    }
}
