//
// Created by TianHongZXY on 2020/4/16.
//
#include <cstdio>
typedef char VerterType;
typedef int EdgeType;
const int MAXVEX = 100;
const int INFINITY = 65535;

typedef struct {
    VerterType vexs[MAXVEX];
    EdgeType arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
}MGraph;

void CreateMGraph(MGraph *G){
    int i, j, w;
    printf("输入顶点数和边数：\n");
    scanf("%d%d", &G->numVertexes, &G->numEdges);
    getchar();
    for(int i = 0; i < G->numVertexes; i++){
        scanf("%c", &G->vexs[i]);
        getchar();
    }
    for(int i = 0; i < G->numVertexes; i++)
        for(int j = 0; j < G->numVertexes; j++)
            G->arc[i][j] = INFINITY;
    for(int k = 0; k < G->numEdges; k++){
        printf("输入边(vi, vj)的下标i, j和权值w：\n");
        scanf("%d%d%d", &i, &j, &w);
        G->arc[i][j] = w;
        G->arc[j][i] = w; // 无向图，对称
    }

}


