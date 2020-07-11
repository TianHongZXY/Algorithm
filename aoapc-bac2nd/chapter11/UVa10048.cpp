#include <cstdio>
#include <cstring>
#define INF 0x3f3f3f3f
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
const int maxn = 100 + 5;
int d[maxn][maxn];
int C, S, Q, kase = 1;

void init(){
    memset(d, 0x3f, sizeof(d));
}

void floyd(){
    for(int k = 1; k <= C; k++)
        for(int i = 1; i <= C; i++)
            for(int j = 1; j <= C; j++){
                if(d[i][k] == INF || d[k][j] == INF) continue;
                d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
            }
    return;
}

int main(){
    int from, to, dist;
    while(scanf("%d%d%d", &C, &S, &Q) == 3 && C){
        init();
        for(int i = 1; i <= S; i++){
            scanf("%d%d%d", &from, &to, &dist);
            d[from][to] = d[to][from] = dist;
        }
        floyd();
        if(kase != 1) printf("\n");
        printf("Case #%d\n", kase++);
        for(int i = 0; i < Q; i++){
            scanf("%d%d", &from, &to);
            if(d[from][to] != INF)
                printf("%d\n", d[from][to]);
            else
                printf("no path\n");
        }
    }
    return 0;
}