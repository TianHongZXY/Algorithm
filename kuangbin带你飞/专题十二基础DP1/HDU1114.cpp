#include <cstdio>
#include <cstring>
#define min(x, y) ((x) < (y) ? (x):(y))
#define INF 0x3f3f3f3f
const int maxn = 500 + 5;
int P[maxn], W[maxn];
int dp[10000 + 10];
int main(){
    int T, n, E, F;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &E, &F);
        int totalw = F - E;
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d%d", &P[i], &W[i]);
        }
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        for(int i = 0; i < n; i++)
            for(int w = W[i]; w <= totalw; w++){
                dp[w] = min(dp[w], dp[w - W[i]] + P[i]);
            }
        if(dp[totalw] == INF)
            printf("This is impossible.\n");
        else
            printf("The minimum amount of money in the piggy-bank is %d.\n", dp[totalw]);
    }

    return 0;
}