//
// Created by TianHongZXY on 2020/4/16.
//
#include <cstdio>
#include <cstring>
#include "ch07.h"
int visited[MAXVEX];


// 邻接图的DFS
void DFS(MGraph G, int i){
    visited[i] = 1;
    printf("%c\n", G.vexs[i]);
//    fflush(stdout); // printf为行缓冲且线程不安全，要么用fflush(不太好用)，要么以\n结尾，不然打印不出来
    for(int j = 0; j < G.numVertexes; j++)
        if(G.arc[i][j] != INFINITY && visited[j] == 0)
            DFS(G, j);
}
void DFStraverse(MGraph G){
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < G.numVertexes; i++)
        if(visited[i] == 0)
            DFS(G, i);
}

// 邻接表的DFS
void DFS(GraphAdjList GL, int i){
    visited[i] = 1;
    printf("%c\n", GL.adjList[i].data);
    EdgeNode *p = GL.adjList[i].firstedge;
    while(p){
        if(visited[p->adjvex] == 0)
            DFS(GL, p->adjvex);
        p = p->next;
    }

}
void DFStraverse(GraphAdjList GL){
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < GL.numVertexes; i++){
        if(visited[i] == 0)
            DFS(GL, i);
    }
}
int main(){
    auto *G = new MGraph;
    CreateMGraph(G);
    DFStraverse(*G);

    auto *GL = new GraphAdjList;
    CreateALGraph(GL);
    DFStraverse(*GL);
    return 0;
}