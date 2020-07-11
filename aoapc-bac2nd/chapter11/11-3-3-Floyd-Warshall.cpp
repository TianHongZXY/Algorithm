#include <cstdio>
#include <cstring>
#define INF 0x3f3f3f3f
#define min(x, y) (x < y ? x : y)
const int maxn = 1e3;
const int maxm = 1e3;
int n, w[maxm], d[maxn][maxn]; // d[i][j] 从i点到j点的最短路长度

void init(){
    memset(d, 0x3f, sizeof(d));
    for(int i = 0; i < n; i++)
        d[i][i] = 0;
}

void floyd(){
    init();
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(d[i][k] < INF && d[k][j] < INF)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}