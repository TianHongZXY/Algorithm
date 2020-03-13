//
// Created by TianHongZXY on 2020/3/6.
//
#include <iostream>
#include <cstring>
using namespace std;
int n, K;
const int MAX_N = 100, MAX_K = 100000;
int a[MAX_N];
int m[MAX_N];
bool dp[MAX_N + 1][MAX_K + 1];

void solve(){
    dp[0][0] = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= K; j++)
            for (int k = 0; k <= m[i] && k * a[i] <= j; k++)
                dp[i + 1][j] |= dp[i][j - k * a[i]];
    if (dp[n][K]) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int dp_2[MAX_K + 1];
void solve_2(){
    memset(dp_2, -1, sizeof(dp_2));
    dp_2[0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= K; j++){
            if (dp_2[j] >= 0) dp_2[j] = m[i];
            else if (j < a[i] || dp_2[j - a[i]] <= 0) dp_2[j] = -1;
            else dp_2[j] = dp_2[j - a[i]] - 1;
        }
    if (dp_2[K] >= 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main(){
    cin >> n >> K;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> m[i];
    solve_2();
    return 0;
}