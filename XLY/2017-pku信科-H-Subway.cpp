#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 300;
const double speed_w = 10000 / 60;
const double speed_s = 40000 / 60;
double d[maxn];
int homex, homey, schoolx, schooly, nodeidx = 0, edgeidx = 0;
double dist[maxn][maxn];
int vis[maxn];
struct Node{
    int x, y;
    vector<int> edges;
}nodes[maxn];

struct Edge{
    int u, v;
    double dist;
}edges[maxn * maxn];

double compute_time(int aidx, int bidx, double speed){
    double res;
    res = sqrt(pow(abs(nodes[aidx].x - nodes[bidx].x), 2) + pow(abs(nodes[aidx].y - nodes[bidx].y), 2)) / speed;
    return res;
}

//void addEdge(Node& a, Node& b, int aidx, int bidx, double speed){
//    edges[edgeidx].u = aidx; edges[edgeidx].v = bidx;
//    if(speed == speed_w)
//        edges[edgeidx].dist = dist[aidx][bidx] = dist[bidx][aidx] = sqrt(pow(abs(a.x - b.x), 2) + pow(abs(a.y - b.y), 2)) / speed;
//    else edges[edgeidx].dist = dist[aidx][bidx] = dist[bidx][aidx] = (abs(a.x - b.x) + abs(a.y - b.y)) / speed;
//    a.edges.push_back(edgeidx);
//    b.edges.push_back(edgeidx);
//    edgeidx++;
//}

void init(){
    for(int i = 0; i < maxn; i++){
        d[i] = INF;
        for(int j = 0; j < maxn; j++){
            dist[i][j] = INF;
        }
    }
    memset(vis, 0, sizeof(vis));
    return;
}

void Dijkstra(){
    int s = 0;
    d[s] = 0;
    for(int i = 0; i < nodeidx; i++){
        int x; double m = INF;
        for(int i = 0; i < nodeidx; i++)
            if(!vis[i] && d[i] < m) m = d[x = i];
        vis[x] = 1;
        for(int y = 0; y < nodeidx; y++)
            d[y] = min(d[y], d[x] + dist[x][y]);
    }
}

int main(){
    init();
    scanf("%d%d%d%d", &homex, &homey, &schoolx, &schooly);
    nodes[nodeidx].x = homex; nodes[nodeidx].y = homey; nodeidx++;
    nodes[nodeidx].x = schoolx; nodes[nodeidx].y = schooly; nodeidx++;
    dist[0][1] = dist[1][0] = compute_time(0, 1, speed_w);
    Node *prev = NULL;
    while(scanf("%d%d", &nodes[nodeidx].x, &nodes[nodeidx].y) == 2){
        if(nodes[nodeidx].x == -1){
            prev = NULL;
            continue;
        }
//        if(nodes[nodeidx].x == -2) break;
        if(prev){
            dist[nodeidx - 1][nodeidx] = dist[nodeidx][nodeidx - 1] = compute_time(nodeidx - 1, nodeidx, speed_s);
        }
        prev = &nodes[nodeidx];
        nodeidx++;
    }
    for(int i = 0; i < nodeidx; i++){
        Node &cur = nodes[i];
        for(int j = 0; j < nodeidx; j++){
            if(i == j) continue;
            dist[i][j] = dist[j][i] = min(compute_time(i, j, speed_w), dist[i][j]);
        }
    }

//    for(int i = 0; i < nodeidx; i++){
//        vis[i] = 1;
//        for(int j = 0; j < nodeidx; j++){
//            if(i == j || vis[j] || dist[i][j] >= INF) continue;
//            printf("(%d, %d) to (%d, %d) costs %d minute(s).\n", nodes[i].x, nodes[i].y, nodes[j].x, nodes[j].y, (int)round(dist[i][j]));
//        }
//    }
    Dijkstra();
//    for(int i = 0; i < nodeidx; i++)
//        printf("%d\n", (int)round(d[i]));
    printf("%d\n", (int)round(d[1]));

    return 0;
}