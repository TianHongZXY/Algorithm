#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define min(x, y) (x < y ? x : y)
const int maxn = 1e3;
const int maxm = 1e3;
int n, m, u[maxn], v[maxn], w[maxm], d[maxn], p[maxn], cnt[maxn]; // cnt[u] 节点u进入队列的次数
bool inQ[maxn]; // inQ[u] = true表明节点u已在队列之中

struct Edge{
    int from, to, dist;
    Edge(int u, int v, int d): from(u), to(v), dist(d) {}
};
vector<Edge> edges;
vector<int> G[maxn];
// 队列版
bool bellman_ford(int s){
    queue<int> Q;
    memset(inQ, 0, sizeof(inQ));
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n; i++) d[i] = INF;
    d[s] = 0;
    Q.push(s);
    inQ[s] = true;
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        inQ[u] = false;
        for(int i = 0; i < G[u].size(); i++){
            Edge& e = edges[G[u][i]];
            if(d[u] < INF && d[e.to] > d[u] + e.dist){
                d[e.to] = d[u] + e.dist;
                p[e.to] = G[u][i];
                if(!inQ[e.to]){
                    Q.push(e.to); inQ[e.to] = true;
                    if(++cnt[e.to] > n) return false; // 图中包含负环
                }
            }
        }
    }
    return true;
}


// 循环版
void bellman_ford1(int s){
    for(int i = 0; i < n; i++) d[i] = INF;
    d[s] = 0;
    for(int k = 0; k < n - 1; k++) // 迭代n-1次，从起点出发，走n-1步，就走完了n个点
        for(int i = 0; i < m; i++){ // 检查每条边
            int x = u[i], y = v[i]; // 第i条边的端点
            if(d[x] < INF) d[y] = min(d[y], d[x] + w[i]); // 松弛
        }
}