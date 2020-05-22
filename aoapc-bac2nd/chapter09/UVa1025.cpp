#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define INF 1<<30
const int maxN = 50 + 5, maxT = 2000;
int has_train[maxT][maxN][2], dp[maxT][maxN];
int n, T, t[maxN], M1, M2, d[maxN], e[maxN];

int main(){
    int kase = 0;
    while(scanf("%d", &n) == 1 && n){
        memset(has_train, 0, sizeof(has_train));
        scanf("%d", &T);
        for(int i = 1; i <= n - 1; i++) scanf("%d", &t[i]); // 从车站i到车站i+1耗费的时间t[i]
        scanf("%d", &M1); // 从左侧发车M1辆
        for(int i = 1; i <= M1; i++){
            scanf("%d", &d[i]); // d[i]时刻左侧发一辆车
            has_train[d[i]][1][0] = 1; // d[i]时刻第1个车站有往右开的车
            int tt = 0;
            for(int j = 1; j <= n - 1; j++){
                tt += t[j];
                has_train[d[i] + tt][j + 1][0] = 1; // 当前的车在d[i] + tt时刻开到第j+1个车站
            }
        }
        scanf("%d", &M2); // 从右侧发车M2辆
        for(int i = 1; i <= M2; i++){
            scanf("%d", &e[i]); // d[i]时刻右侧发一辆车
            has_train[e[i]][n][1] = 1; // d[i]时刻第n个车站有往左开的车
            int tt = 0;
            for(int j = n - 1; j >= 1; j--){
                tt += t[j];
                has_train[e[i] + tt][j][1] = 1;
            }
        }

        for(int i = 1; i <= n - 1; i++) dp[T][i] = INF;
        dp[T][n] = 0;
        for(int i = T - 1; i >= 0; i--)
            for(int j = 1; j <= n; j++){ // i时刻在j车站的情况下，到达终点n所需要的总共在车站台上等待的时间
                dp[i][j] = dp[i + 1][j] + 1; // 在站台上等1分钟
                if(j < n && has_train[i][j][0] && i + t[j] <= T)
                    dp[i][j] = min(dp[i][j], dp[i+t[j]][j+1]); // 是等一分钟之后需要等的时间长，还是坐上往右开的车之后要等的时间长
                if(j > 1 && has_train[i][j][1] && i + t[j-1] <= T)
                    dp[i][j] = min(dp[i][j], dp[i+t[j-1]][j-1]);
            }
        printf("Case Number %d: ", ++kase);
        if(dp[0][1] >= INF) printf("impossible\n");
        else printf("%d\n", dp[0][1]);
    }
    return 0;
}