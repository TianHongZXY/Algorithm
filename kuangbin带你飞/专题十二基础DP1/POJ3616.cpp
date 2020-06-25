#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e6 + 10;
const int maxm = 1e3 + 10;
int dp[maxm];

struct milk{
    int s, e, eff;
    bool operator < (const milk rhs) const{
        return this->e < rhs.e;
    }
}m[maxm];

int main(){
    int N, M, R;
    scanf("%d%d%d", &N, &M, &R);
    for(int i = 0; i < M; i++){
        scanf("%d%d%d", &m[i].s, &m[i].e, &m[i].eff);
        m[i].e += R;
    }
    sort(m, m + M);
    int ans = -1;
    for(int i = 0; i < M; i++){
        dp[i] = m[i].eff;
        for(int j = 0; j < i; j++){
            if(m[i].s >= m[j].e)
                dp[i] = max(dp[i], dp[j] + m[i].eff);
        }
        ans = max(dp[i], ans);
    }
    printf("%d\n", ans);
    
    return 0;
}