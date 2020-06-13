#include <cstdio>
#include <cstring>
#define INF (1<<30)
#define max(x, y) ((x) > (y) ? (x) : (y))
const int maxn = 1000000 + 10;
int S[maxn], dp[maxn], pre[maxn];
int main(){
    int m, n;
    while(scanf("%d%d", &m, &n) == 2){
        for(int i = 1; i <= n; i++){
            scanf("%d", &S[i]);
        }
        memset(dp, 0, sizeof(dp));
        memset(pre, 0, sizeof(pre));
        int maxx;
        for(int i = 1; i <= m; i++){
            maxx = -INF;
            for(int j = i; j <= n; j++){
                dp[j] = max(dp[j - 1], pre[j - 1]) + S[j];
                pre[j - 1] = maxx;
                maxx = max(dp[j], maxx);
            }
        }
        printf("%d\n", maxx); // 退出循环时，maxx = (dp[n], maxx), dp[n]是选了第n个数，而maxx是选或没选第n个数中大的那个
    }
    return 0;
}