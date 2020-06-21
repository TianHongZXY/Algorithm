#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 50 + 5;
ll cnt = 0;
queue<int> Q;

bool contain4(int x){
    return ((x % 10 == 4) || (x / 10 == 4));
}

// BFS解法
// int main(){
//     int n, k;
//     while(scanf("%d%d", &n, &k) == 2 && n && k){
//         for(int i = 1; i <= k; i++){
//             if(!contain4(i))
//                 Q.push(i);
//         }
//         while(!Q.empty()){
//             int cur = Q.front(); Q.pop();
//             if(cur == n){
//                 cnt++; continue;
//             }
//             for(int i = 1; i <= k; i++){
//                 if(!contain4(i)){
//                     if(cur + i < n){
//                         Q.push(cur + i);
//                     }
//                     else if(cur + i == n){
//                         cnt++;
//                         break;
//                     }
//                 }
//             }
//         }
//         printf("%lld\n", cnt);
//         cnt = 0;
//     }
//     return 0;
// }
#include <cstring>
ll dp[maxn];
// DP解法， 到第n层台阶的走法dp[n]共有dp[n - 1] + dp[n - 2] + ··· + dp[n - k]种
int main(){
    int n, k;
    while(scanf("%d%d", &n, &k) == 2 && n && k){
        dp[0] = 1; // 假设要走到k层，那么可以一步走k步到达，即dp[i - k] = 1
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= min(i, k); j++){
                if(contain4(j)) continue;
                dp[i] += dp[i - j];
            }
        }
        cout << dp[n] << endl;
//        printf("%lld\n", dp[n]);
        memset(dp, 0, sizeof(dp));
    }
}