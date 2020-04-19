//
// Created by TianHongZXY on 2020/4/17.
//
#include "十字链表.h"
#include <stack>
#include <cstring>
#include <cstdio>
using namespace std;
int visited[MAXVEX];
// 拓扑排序从小到大是入度为0的点

void dfs(GraphAdjList G, int i, stack<VertexNode>& stk){
    visited[i] = 1;
    EdgeNode* temp = G.adjList[i].firstout;
    while(temp){
        if(!visited[temp->headvex]){
            dfs(G, temp->headvex, stk);
        }
        temp = temp->taillink;
    }
    //由于加入顶点到集合中的时机是在dfs方法将退出的时候，
    //而dfs方法本身是个递归方法，
    //只要当前顶点还存在边指向其他顶点，
    //它就会递归调用dfs方法，而不会退出。
    //因此，退出dfs方法，意味着当前顶点没有指向其他顶点的边了，
    //当前顶点是一条路径上的最后一个顶点，出度为0
    stk.push(G.adjList[i]);
}

void toposort_by_dfs(GraphAdjList G){
    memset(visited, 0, sizeof(visited));
    stack<VertexNode> stk;
    printf("基于DFS的拓扑排序为：\n");
    for(int i = 0;  i < G.numVertexes; i++){
        if(!visited[i])
            dfs(G, i, stk);
    }
    //输出拓扑序列，因为我们每次都是找到了出度为0的顶点加入栈中，
    //所以输出时先进后出，这样其实是让入度为0的顶点先出栈
    while(!stk.empty()){
        VertexNode v = stk.top(); stk.pop();
        printf("%c\n", v.data);
    }
}

int main(){
    auto *G = new GraphAdjList;
    CreateALGraph(G);
    toposort_by_dfs(*G);

    return 0;
}