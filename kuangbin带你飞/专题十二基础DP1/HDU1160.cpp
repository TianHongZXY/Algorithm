#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;
const int maxn = 1000 + 10;
int dp[maxn], pre[maxn];
struct mouse{
    int W, S, idx;
    bool operator < (const mouse& rhs){
        if(W < rhs.W) return true;
        else if(W == rhs.W && S > rhs.S) return true;
        else return false;
    }
}mice[maxn];

int main(){
    int n = 1;
    while(scanf("%d%d", &mice[n].W, &mice[n].S) == 2){
        mice[n].idx = n;
        n++;
    }
    sort(mice + 1, mice + n);
    for(int i = 1; i < n; i++){
        dp[i] = 1;
        pre[i] = -1;
    }
    for(int i = 1; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(mice[j].S < mice[i].S && mice[j].W != mice[i].W){
                if(dp[j] < dp[i] + 1){
                    dp[j] = dp[i] + 1;
                    pre[j] = i;
                }
            }
    int ans = -1, ansidx = -1;
    for(int i = 1; i < n; i++)
        if(dp[i] > ans){
            ans = dp[i]; ansidx = i;
        }
    printf("%d\n", ans);
    stack<mouse> res;
    while(ansidx != -1){
        res.push(mice[ansidx]);
        ansidx = pre[ansidx];
    }
    while(!res.empty()){
        printf("%d\n", res.top().idx);
        res.pop();
    }
    return 0;
}