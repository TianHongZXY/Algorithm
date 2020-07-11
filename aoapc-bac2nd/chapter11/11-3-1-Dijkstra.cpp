#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 1e3 + 5;
const int maxm = 1e4 + 5;


namespace n2_dijkstra{
    int n, m; // 节点，边
    int first[maxn]; // first[u]保存节点u的第一条边的编号
    // d[i]为起点到点i的最短距离，next[u]保存编号为u的边的下一条边，w[i][j]为两点距离，不邻接则为INF
    int u[maxm], v[maxm], d[maxm], next[maxm], w[maxn][maxn];
    int vis[maxn];
    void read_graph(){ // 读入有向图的边列表，建立邻接表，编号为e的边从节点u[e]指向节点v[e]，同时建立了无向图，存入邻接矩阵到w[x][y]
        scanf("%d%d", &n, &m);
        memset(w, 0x3f, sizeof(w));
        for(int i = 0; i < n; i++) first[i] = -1;
        for(int e = 0; e < m; e++){
            scanf("%d%d%d", &u[e], &v[e], &w[u[e]][v[e]]);
            w[v[e]][u[e]] = w[u[e]][v[e]];
            next[e] = first[u[e]]; // 头插法，将边e插入 从节点u[e]出发的边的链表 中
            first[u[e]] = e; // 将节点u[e]的第一条边设为e
        }
    }

    int dijkstra(int start_node){
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; i++) d[i] = (i == start_node ? 0 : INF);
        for(int i = 0; i < n; i++){
            int x, m = INF;
            for(int y = 0; y < n; y++) if(!v[y] && d[y] < m) m = d[x = y]; // 找到d值最小即离起点最近的点，第一次找到的就是起点
            v[x] = 1;
            for(int y = 0; y < n; y++) d[y] = min(d[y], d[x] + w[x][y]); // 对所有其他点，更新其到当前离起点最近点的最短距离
        }
    }
}

namespace mlogn_dijkstra{
    struct Edge{
        int from, to, dist;
        Edge(int u, int v, int d): from(u), to(v), dist(d) {}
    };

    struct Dijkstra{
        int n, m, from, to, dist, idx;
        vector<Edge> edges;
        vector<int> G[maxn];
        bool done[maxn];
        int d[maxn]; // s到各个点的距离
        int p[maxn]; // p[u]为从源点到达u点的最短路中的上一条弧的编号

        void read_graph(){ // 读入有向图，使用vector建立邻接表
            scanf("%d%d", &n, &m);
            init(n);
            for(int e = 0; e < m; e++){
                scanf("%d%d%d", &from, &to, &dist);
                AddEdge(from, to, dist);
            }
        }
        void init(int n){
            this->n = n;
            for(int i = 0; i < n; i++) G[i].clear();
            edges.clear();
            memset(done, 0, sizeof(done));
        }

        void AddEdge(int from, int to, int dist){
            edges.push_back(Edge(from, to, dist));
            idx = edges.size();
            G[from].push_back(idx - 1); // 该条边的编号为idx-1，从0开始，将其加入从起点from出发的边列表
        }

        typedef pair<int, int> pii;
        void dijkstra(int s){
            priority_queue<pii, vector<pii>, greater<pii> > Q; // priority_queue<存储的类型, 容器类型(默认用vector存储), 比较函数>
            for(int i = 0; i < n; i++) d[i] = INF;
            d[s] = 0;
            Q.push(make_pair(d[s], s));
            while(!Q.empty()){
                pii x = Q.top(); Q.pop();
                int u = x.second;
                if(done[u]) continue;
                done[u] = true;
                for(int i = 0; i < G[u].size(); i++){ // 对每个从节点u出发的边都考察一次，然后将u添加到done，程序合计共执行了m次即边的个数
                    Edge& e = edges[G[u][i]];
                    if(d[e.to] > d[u] + e.dist){ // 这步往往条件不成立，也就不执行下面的入队操作，所以其实达不到m*logn的时间复杂度
                        d[e.to] = d[u] + e.dist;
                        p[e.to] = G[u][i];
                        Q.push(make_pair(d[e.to], e.to)); // 优先队列的下压操作 logn时间，因此算法复杂度为O(mlogn)
                    }
                }
            }

        }
    };
}





int main(){
    n2_dijkstra::read_graph();
    n2_dijkstra::dijkstra(0);

    return 0;
}