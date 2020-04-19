//
// Created by TianHongZXY on 2020/4/17.
//
#include <cstdio>
#include <cstring>
#include <queue>
#include "ch07.h"
using namespace std;

int visited[MAXVEX];

void BFStraverse(MGraph G){
    queue<int> q;
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < G.numVertexes; i++){
        if(!visited[i]){
            visited[i]  = 1;
            printf("%c\n", G.vexs[i]); // 访问当前点
            q.push(i); // 将当前点入队
            while(!q.empty()){
                i = q.front(); q.pop();
                for(int j = 0; j < G.numVertexes; j++){ // 访问出队结点的所有邻接点，再将它们入队
                    if(G.arc[i][j] != INFINITY && !visited[j]){
                        visited[j] = 1;
                        printf("%c\n", G.vexs[j]);
                        q.push(j);
                    }
                }
            }
        }
    }
}

void BFStraverse(GraphAdjList GL){
    EdgeNode *p;
    queue<int> q;
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < GL.numVertexes; i++){
        if(!visited[i]){
            visited[i] = 1;
            printf("%c\n", GL.adjList[i].data);
            q.push(i);
            while(!q.empty()){
                i = q.front(); q.pop();
                p = GL.adjList[i].firstedge;
                while(p){
                    if(!visited[p->adjvex]){
                        visited[p->adjvex] = 1;
                        printf("%c\n", GL.adjList[p->adjvex].data);
                        q.push(p->adjvex);
                    }
                    p = p->next;
                }
            }
        }
    }
}

int main(){
//    auto *G = new MGraph;
//    CreateMGraph(G);
//    BFStraverse(*G);

    auto *GL = new GraphAdjList;
    CreateALGraph(GL);
    BFStraverse(*GL);
    return 0;
}