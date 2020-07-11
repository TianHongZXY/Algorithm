#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e3;
int n, m; // 结点的个数与边的个数
int u[maxn], v[maxn], w[maxn], r[maxn], p[maxn]; // 分别代表第i条边的两个端点、权值、权值第i小的边的序号与第i个结点的父节点

int cmp(const int i, const int j){ return w[i] < w[j]; };

int find(int x){ return p[x] == x ? x : p[x] = find(p[x]); } // 寻找父节点，同时压缩路径，将每个结点直接与其父节点相连

int Kruskal(){
    int ans = 0;
    for(int i = 0; i < n; i++) p[i] = i; // 初始化并查集
    for(int i = 0; i < m; i++) r[i] = i; // 初始化边序号
    sort(r, r + m, cmp); // r[i]存储着权值第i小的边的序号
    for(int i = 0; i < m; i++){
        int e = r[i]; int x = find(u[e]); int y = find(v[e]);
        if(x != y){ ans += w[e]; p[x] = y; } // 将第e条边加入最小生成树，将x的父节点设为y，连通x与y
    }
    
    return ans;
}