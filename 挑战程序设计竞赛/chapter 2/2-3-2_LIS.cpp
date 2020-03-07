//
// Created by TianHongZXY on 2020/3/7.
//
#include <iostream>
#define INF 2147483647
using namespace std;
int n;
const int MAX_N = 1000;
int a[MAX_N];

void solve(){
    int res = 0;
    int dp[n];
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        res = max(res, dp[i]);
    }
    cout << res << endl;
}

void solve_2(){
    int dp[n];
    fill(dp, dp+n, INF);
    for (int i = 0; i < n; i++){
        *lower_bound(dp, dp + n, a[i]) = a[i];
    }
    cout << lower_bound(dp, dp + n, INF) - dp;
}
int main(){
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    solve_2();
    return 0;
}