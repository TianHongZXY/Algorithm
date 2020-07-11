// https://acm.ecnu.edu.cn/problem/3302/
#include <cstdio>
#include <cstring>
#define min(x, y) (x < y ? x : y)
const int maxn = 1e7 + 10;
long long dp[maxn];

int main(){
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    dp[1] = x;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + x;
        if(i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + y);
        else{
            dp[i] = min(min(dp[(i - 1) / 2], dp[(i + 1) / 2]) + y + x, dp[i]);
        }
    }
    printf("%lld", dp[n]);
    return 0;
}