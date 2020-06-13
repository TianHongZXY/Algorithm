#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 200 + 5, maxm = 20 + 1, offset = 400, maxk = 800 + 5;
int p[maxn], d[maxn];
int dp[maxn][maxm][maxk], res[maxm];
int main(){
    int n, m, kase = 0;
    while(scanf("%d%d", &n, &m) == 2 && n){
        memset(dp, -0x3f, sizeof(dp));
        for(int i = 1; i <= n; i++)
            scanf("%d%d", &p[i], &d[i]);
        dp[0][0][offset] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= m && j <= i; j++)
                for(int k = 0; k <= maxk; k++){
                    dp[i][j][k] = dp[i - 1][j][k];
                    int t = k - (p[i] - d[i]);
                    if(t < 0 || j < 1 || t > offset * 2) continue;
                    dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - 1][t] + p[i] + d[i]);
                }
        }
        int idx = 0;
        while(dp[n][m][idx + offset] < 0 && dp[n][m][-idx + offset] < 0) idx++;
        idx = (dp[n][m][idx + offset] > dp[n][m][-idx + offset] ? (idx + offset) : (-idx + offset));
        int i = n, j = m, cnt = 0, PJ = 0, DJ = 0;
        while(j){
            if(dp[i][j][idx] == dp[i - 1][j][idx]){
                i--;
            }
            else{
                res[cnt++] = i;
                PJ += p[i];
                DJ += d[i];
                idx -= (p[i] - d[i]);
                i--; j--;
            }
        }
        if(kase) printf("\n");
        printf("Jury #%d\n", ++kase);
        printf("Best jury has value %d for prosecution and value %d for defence:\n", PJ, DJ);
        sort(res, res + cnt);
        for(int x = 0; x < cnt; x++){
            printf(" %d", res[x]);
        }
        printf("\n");
    }

    return 0;
}