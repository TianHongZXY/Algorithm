#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 55;
struct state{
    int num, len;
    bool operator < (const state& rhs) const{
        return num < rhs.num;// || (num == rhs.num && len < rhs.len);
    }
}dp[maxn * 180];

int main(){
    int n, T, max_t, t[maxn], kase = 0;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &max_t);
        memset(dp,0,sizeof(dp));
        for(int i = 1; i <= n; i++) scanf("%d", &t[i]);
        for(int i = 1; i <= n; i++)
            for(int j = max_t - 1; j >= t[i]; j--){
                state tmp;
                tmp.num = dp[j - t[i]].num + 1;
                tmp.len = dp[j - t[i]].len + t[i];
                if(dp[j] < tmp) dp[j] = tmp;
            }
        printf("Case %d: %d %d\n", ++kase, dp[max_t-1].num+1, dp[max_t-1].len+678);
    }
    return 0;
}