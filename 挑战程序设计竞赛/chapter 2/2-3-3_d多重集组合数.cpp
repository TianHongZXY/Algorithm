//
// Created by TianHongZXY on 2020/3/7.
//
#include <iostream>
using namespace std;
const int MAX_N = 1000, MAX_M = 1000;
int dp[MAX_N + 1][MAX_M + 1];
int n, m, M;
int a[MAX_N];

void solve(){
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= m; j++){
            if (j - 1 - a[i] >= 0)
                dp[i + 1][j] = (dp[i][j] + dp[i + 1][j - 1] - dp[i][j - 1 - a[i]] + M) % M;
            else
                dp[i + 1][j] = (dp[i][j] + dp[i + 1][j - 1]) % M;
        }
    cout << dp[n][m] << endl;
}

int main(){
    cin >> n >> m >> M;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    solve();
    return 0;
}