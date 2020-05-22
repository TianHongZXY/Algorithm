#include <cstdio>
#include <cstring>
const int maxm = 10 + 5, maxn = 100 + 10;
int dp[maxm][maxn], maze[maxm][maxn], next[maxm][maxn]; // 从(i,j)走到最后一列还需要的最少dp[i][j]
#define INF (1 << 30)

int main(){
    int m, n;
    while(scanf("%d%d", &m, &n) == 2 && m && n){
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++) scanf("%d", &maze[i][j]);
        for(int i = 1; i <= m; i++) dp[i][n] = maze[i][n];
        for(int j = n - 1; j >= 1; j--)
            for(int i = 1; i <= m; i++){
                dp[i][j] = maze[i][j] + dp[i][j+1];
                next[i][j] = i;
                int upidx = (i-1 == 0 ? m : i-1), downidx = (i+1 == m+1 ? 1 : i+1);
                int up = maze[i][j] + dp[upidx][j+1];
                int down = maze[i][j] + dp[downidx][j+1];
                if(up < dp[i][j] || (up == dp[i][j] && upidx < next[i][j])) { next[i][j] = upidx; dp[i][j] = up; } // 让字典序最小
                if(down < dp[i][j] || (down == dp[i][j] && downidx < next[i][j])) { next[i][j] = downidx; dp[i][j] = down; }
            }
        int begin_row, ans = INF;
        for(int i = 1; i <= m; i++){
            if(dp[i][1] < ans) { ans = dp[i][1]; begin_row = i; }
        }
        int col = 1;
        printf("%d", begin_row);
        while(col != n){
            begin_row = next[begin_row][col++];
            printf(" %d", begin_row);
        }
        printf("\n%d\n", ans);
    }

    return 0;
}