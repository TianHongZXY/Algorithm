//
// Created by TianHongZXY on 2020/2/26.
//
#include <iostream>
#include <string.h>
using namespace std;

const int MAX_N = 100, MAX_W = 10000;
int n, W;
int w[MAX_N], v[MAX_N];
int dp[MAX_N][MAX_W];
int rec(int i, int j){
    if (dp[i][j] >= 0) return dp[i][j];
    int res;
    if (i == n) res = 0; // 无剩余物品
    else if (j < w[i]) res = rec(i + 1, j); // 当前的物品重量[i]大于剩余的载重量
    else res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
    return dp[i][j] = res;
}

void solve(){
    memset(dp, -1, sizeof(dp));
    cout << rec(0, W) << endl;
}

void backward_dp_solve(){
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j <= W; j++){
            if (j < w[i])
                dp[i][j] = dp[i + 1][j];
            else
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
        }
    cout << dp[0][W] << endl;
}

void forward_dp_solve(){
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= W; j++){
            if (j < w[i]) dp[i + 1][j] = dp[i][j];
            else dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
        }
    cout << dp[n][W] << endl;
}
int main(){
    cin >> n >> W;
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];

    backward_dp_solve();
}