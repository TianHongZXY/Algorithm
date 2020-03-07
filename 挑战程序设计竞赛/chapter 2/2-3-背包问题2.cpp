//
// Created by TianHongZXY on 2020/3/5.
//
#include <math.h>
#include <iostream>
using namespace std;

const int MAX_N = 100, MAX_V = 100, MAX_W = pow(10, 9);
int n, W;
int w[MAX_N + 1], v[MAX_N + 1];
void solve(){
    int DP[n + 1][(n * MAX_V) + 1];
    fill(DP[0], DP[0] + n * MAX_V + 1, 1000000);
    DP[0][0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n * MAX_V; j++){
            if (j < v[i])
                DP[i + 1][j] = DP[i][j];
            else
                DP[i + 1][j] = min(DP[i][j], DP[i][j - v[i]] + w[i]);
        }
    int res = 0;
    for (int i = 0; i <= n * MAX_V; i++) if (DP[n][i] <= W) res = i;
    cout << res << endl;
}

int main(){
    cin >> n >> W;
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];
    solve();
    return 0;
}