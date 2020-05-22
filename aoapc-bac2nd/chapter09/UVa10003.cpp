#include <cstdio>
#include <cstring>
#define min(a,b) ( ((a)>=(b))?(b):(a) )
const int maxn = 50 + 5;
int dp[maxn][maxn];
int cut[maxn];
int n, l;

int dp_cut(int i, int j){
    if(dp[i][j]) return dp[i][j];
    if(i + 1 == j) return 0;
    for(int k = i + 1; k < j; k++){
        if(dp[i][j] > dp_cut(i, k) + dp_cut(k, j) || dp[i][j] == 0)
            dp[i][j] = dp_cut(i, k) + dp_cut(k, j);
    }
    dp[i][j] += cut[j] - cut[i];
    return dp[i][j];
}

int main(){
    while(scanf("%d", &l) == 1 && l){
        scanf("%d", &n);
        cut[0] = 0; cut[n + 1] = l;
        for(int i = 1; i <= n; i++)
            scanf("%d", &cut[i]);
        int ans = dp_cut(0, n + 1);
        printf("The minimum cutting is %d.\n", ans);
        memset(dp, 0, sizeof(dp));
    }

    return 0;
}