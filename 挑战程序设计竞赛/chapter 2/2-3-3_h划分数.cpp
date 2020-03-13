//
// Created by TianHongZXY on 2020/3/7.
//
#include <iostream>
#include <cstring>
using namespace std;
int n, m, M;

void solve(){
    int dp[m + 1][n + 1];
    memset(dp, 0 ,(m + 1) * (n + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++)
        for (int j = 0; j <= n; j++){
            if (j < i) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = (dp[i][j - i] + dp[i - 1][j]) % M;
        }
    cout << dp[m][n];
}

int main(){
    cin >> n >> m >> M;
    solve();
}