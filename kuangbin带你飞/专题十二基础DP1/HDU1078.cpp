#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <iostream>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 1e2 + 5;
int a[maxn][maxn];
int dp[maxn][maxn];
int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};
int n, k;

bool ingrid(int xx, int yy){
    return (xx > 0 && xx <= n && yy > 0 && yy <= n);
}

int dfs(int x, int y){
    if(dp[x][y]) return dp[x][y];
    int mx = 0;
    for(int i = 1; i <= k; i++){ // 走到x,y处，下一步可以横/竖连走1~k步，都进行dfs
        for(int j = 0; j < 4; j++){
            int xx = x + dx[j] * i, yy = y + dy[j] * i;
            if(ingrid(xx, yy) && a[x][y] < a[xx][yy])
                mx = max(dfs(xx, yy), mx);
        }
    }
    return dp[x][y] = a[x][y] + mx;
}

int main(){
    while(scanf("%d%d", &n, &k) && n != -1 && k != -1){
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                scanf("%d", &a[i][j]);
        memset(dp, 0, sizeof(dp));
        printf("%d\n", dfs(1, 1));
    }

    return 0;
}