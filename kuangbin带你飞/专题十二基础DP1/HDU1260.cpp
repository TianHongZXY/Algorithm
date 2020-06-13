#include <cstdio>
#include <cstring>
#define min(x, y) ((x) < (y) ? (x) : (y))
const int maxk = 2000 + 10;
int T[maxk], J[maxk], dp[maxk];

int main(){
    int n, k, time;
    scanf("%d", &n);
    while(n--){
        int hh = 8, mm = 0, ss = 0;
        scanf("%d", &k);
        for(int i = 0; i < k; i++)
            scanf("%d", &T[i]);
        for(int i = 0; i < k - 1; i++)
            scanf("%d", &J[i]);
        dp[0] = T[0];
        dp[1] = min(T[0] + T[1], J[0]); // 设dp[i]为给第i个客户卖完票后的总耗时
        for(int i = 2; i < k; i++){
            dp[i] = min(dp[i - 1] + T[i], dp[i - 2] + J[i - 1]); // dp[i]的耗时等于 单独给第i个客户卖票 和 给第i-1与第i个客户一起卖票 的最小值
        }
        time = dp[k - 1];
        hh = time / 3600 + hh;
        mm = (time - 3600 * (hh-8)) / 60;
        ss = time % 60;
        printf("%02d:%02d:%02d %s\n", hh, mm, ss, hh >= 12 ? "pm" : "am");
    }

    return 0;
}