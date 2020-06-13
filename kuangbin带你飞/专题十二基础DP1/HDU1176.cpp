#include <cstdio>
#include <cstring>
#define max(x, y) ((x) > (y) ? (x) : (y))
const int maxn = 100000 + 10;
int pieces[11][maxn], dp[11][maxn];

int main(){
    int n, x, T, maxT = -1;
    while(scanf("%d", &n) == 1 && n){
        for(int i = 0; i < n; i++){
            scanf("%d%d", &x, &T);
            pieces[x][T]++;
            maxT = max(T, maxT);
        }
        for(int i = 0; i < 11; i++)
            dp[i][maxT] = pieces[i][maxT]; // 在最后一个时刻的在i位置最多能接到几个馅饼
        for(int t = maxT - 1; t >= 0; t--) // 反向dp，当前时刻t在i位置能最多接到几个馅饼只与上一时刻t+1有可能的三个位置(i-1, i, i+1)有关
            for(int i = 0; i < 11; i++){
                if(i - 1 >= 0)
                    dp[i][t] = max(dp[i - 1][t + 1] + pieces[i][t], dp[i][t]);
                if(i + 1 <= 10)
                    dp[i][t] = max(dp[i + 1][t + 1] + pieces[i][t], dp[i][t]);
                dp[i][t] = max(dp[i][t], dp[i][t + 1] + pieces[i][t]);
            }
        printf("%d\n", dp[5][0]);
        memset(dp, 0, sizeof(dp));
        memset(pieces, 0, sizeof(dp));
    }

    return 0;
}