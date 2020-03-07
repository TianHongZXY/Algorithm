//
// Created by TianHongZXY on 2020/2/29.
//
#include <iostream>
using namespace std;

const int MAX_W = 10000;
const int MAX_N = 100;
int n, W;
int w[MAX_N + 1];
int v[MAX_N + 1];

void solve(){
    int dp[MAX_N + 1][MAX_W];
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= W; j++){
            if (j < w[i])
                dp[i + 1][j] = dp[i][j];
            else
                dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - w[i]] + v[i]);
        }
    cout << dp[n][W] << endl;
}

void solve_2(){
    int dp_2[2][MAX_W+1];
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= W; j++){
            if (w[i] > W)
                dp_2[(i + 1) & 1][j] = dp_2[i & 1][j];
            else
                dp_2[(i + 1) & 1][j] = max(dp_2[(i + 1) & 1][j - w[i]] + v[i], dp_2[i & 1][j]);
        }
    cout << dp_2[n & 1][W];

}

void solve_3(){
    int dp_3[MAX_W+1];
    for (int i = 0; i < n; i++)
        for (int j = w[i]; j <= W; j++)
            dp_3[j] = max(dp_3[j], dp_3[j - w[i]] + v[i]);
    cout << dp_3[W];
}

int main(){
    cin >> n >> W;
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];
    solve_3();
    return 0;
}