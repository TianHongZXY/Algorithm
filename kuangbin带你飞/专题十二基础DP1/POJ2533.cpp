#include <cstdio>
#define max(x, y) ((x) > (y) ? x : y)
const int maxn = 1000 + 10;
int dp[maxn];
int a[maxn];
int main(){
    int n;
    while(scanf("%d", &n) == 1 && n){
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int ans = -1;
        for(int i = 0; i < n; i++){
            dp[i] = 1;
            for(int j = 0; j < i; j++){
                if(a[i] > a[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(dp[i], ans);
        }
        printf("%d\n", ans);
    }

    return 0;
}