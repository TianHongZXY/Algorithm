#include <cstdio>
#define max(x, y) ((x) > (y) ? (x) : (y))
#define INF 0x3f3f3f3f
const int maxn = 1000 + 10;
int chess[maxn], dp[maxn]; // dp[i]为以chess[i]作为结尾的最大上升子序列和

int main(){
    int n;
    while(scanf("%d", &n) == 1 && n){
        for(int i = 0; i < n; i++)
            scanf("%d", &chess[i]);
        for(int i = 0; i < n; i++){
            dp[i] = chess[i];
            for(int j = 0; j < i; j++){
                if(chess[j] < chess[i])
                    dp[i] = max(dp[i], dp[j] + chess[i]);
            }
        }
        int ans = -INF;
        for(int i = 0; i < n; i++){
            ans = max(ans, dp[i]);
        }
        printf("%d\n", ans);
    }

    return 0;
}