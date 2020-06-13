#include <cstdio>
#include <cstring>
#define max(x, y) ((x) > (y) ? (x) : (y))
const int maxn = 1000;
int h[maxn], dp[maxn];

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        for(int i = 0; i < n; i++){
            scanf("%d", &h[i]);
            dp[i] = 1;
        }
        int ans = -1;
        for(int i = 0; i < n; i++){ // dp[i]代表拦截前i个导弹需要多少台拦截系统
            for(int j = i + 1; j < n; j++)
                if(h[j] > h[i]) // 假设第j个导弹，比拦截的第i个导弹的高度高
                    dp[j] = max(dp[j], dp[i] + 1); // 那么想拦截至少得比拦截前i个导弹多一个拦截系统才行
            ans = max(ans, dp[i]); // 本质是求最长上升子序列的长度，因为每次上升都意味着要多一个拦截系统，但下降是不需要的
        }
        printf("%d\n", ans);
    }
    return 0;
}