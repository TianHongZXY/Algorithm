//
// Created by TianHongZXY on 2020/4/16.
//
//
// Created by TianHongZXY on 2020/4/16.
//
#include <cstdio>
typedef char VerterType;
typedef int EdgeType;
const int MAXVEX = 100;

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

void CreateALGraph(GraphAdjList *G){
    int i, j, w;
    printf("输入顶点数和边数：\n");
    scanf("%d%d", &G->numVertexes, &G->numEdges);
    printf("输入每个点的data：\n");
    for(int k = 0; k < G->numVertexes; k++){
        getchar();
        scanf("%c", &G->adjList[k].data);
        G->adjList[k].firstin = NULL;
        G->adjList[k].firstout = NULL;
    }
    for(int k = 0; k < G->numEdges; k++){
        printf("输入边<vi, vj>的下标i, j和权值w：\n"); // 由i指向j
        scanf("%d%d%d", &i, &j, &w);
        EdgeNode *e1 = new EdgeNode; // e1是j的firstin新的一员
        e1->headvex = j;
        e1->tailvex = i;
        e1->weight = w;
        e1->headlink = G->adjList[j].firstin; // 链表的头插法，新结点的headlink替代原firstin
        G->adjList[j].firstin = e1;

        EdgeNode *e2 = new EdgeNode; // e2是i的firstout新的一员
        e2->headvex = j;
        e2->tailvex = i;
        e2->weight = w;
        e2->taillink = G->adjList[i].firstout;
        G->adjList[i].firstout = e2;
    }
}

