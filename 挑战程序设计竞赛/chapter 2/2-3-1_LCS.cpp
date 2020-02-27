//
// Created by TianHongZXY on 2020/2/26.
//
#include <iostream>
using namespace std;


int n, m;
const int MAX_N = 1000;
char s[MAX_N], t[MAX_N];
int dp[MAX_N + 1][MAX_N + 1];

void solve(){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i] == t[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
            else dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    cout << dp[n][m] << endl;
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int j = 0; j < m; j++)
        cin >> t[j];
    solve();
    return 0;
}