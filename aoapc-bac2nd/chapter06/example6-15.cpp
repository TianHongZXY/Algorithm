//
// Created by TianHongZXY on 2020/4/15.
//
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
int c[maxn];
int G[maxn][maxn];
int topo[maxn];
int n, t;
int vis[maxn][maxn];
stack<int> stk;

bool dfs(int u){
    c[u] = -1;
    for(int v = 1; v <= n; v++)
        if(G[u][v] == 1){
            if(c[v] < 0) return false;
            else if(c[v] == 0 && !dfs(v)) return false;
        }
    c[u] = 1; topo[t--] = u;
    return true;
}

bool toposort(){
    memset(c, 0, sizeof(c));
    for(int u = 1; u <= n; u++)
        if(c[u] == 0)
            if(!dfs(u)) return false;
    return true;
}

void euler(int u){
    // 欧拉道路时，开始的u必须是起点，欧拉回路时任意
    for(int v = 0; v < n; v++){ // 走完和u相连的所有边
        if(G[u][v] && !vis[u][v]){ // 如果(u, v)两点相连且该边没访问过
            vis[u][v] = vis[v][u] = 1; // 若G为有向图，则改为vis[u][v] = 1
            euler(v); // 走完与v相连的所有边
            stk.push(v); // 将v和u压入栈，最后弹出的顺序是访问顺序 u-->v-->...
            stk.push(u);
        }
    }
}

int main(){
    int m, u, v;
    while(scanf("%d%d", &n, &m) == 2 && n){
        memset(G, 0, sizeof(G));
        t = n;
        for(int i = 0; i < m; i++){
            scanf("%d%d", &u, &v);
            G[u][v] = 1;
        }
        if(toposort()){
            bool first = true;
            for(int i = 1; i <= n; i++){
                if(first) first = false;
                else cout << " ";
                cout << topo[i];
            }
            cout << endl;
        }
    }
    return 0;

}