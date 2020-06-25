#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 2e3 + 10;
int a[maxn], b[maxn], dp[2][maxn];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    int idx = 1;
    for(int i = 1; i <= n; i++){
        int mn = dp[idx^1][1];
        for(int j = 1; j <= n; j++){
            mn = min(mn, dp[idx^1][j]);
            dp[idx][j] = abs(a[i] - b[j]) + mn;
        }
        idx ^= 1;
    }
    idx ^= 1;
    int ans = dp[idx][1];
    for(int i = 2; i <= n; i++)
        ans = min(dp[idx][i], ans);
    printf("%d\n", ans);

    return 0;
}