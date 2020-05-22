#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 1<<30
using namespace std;
const int maxn = 10000 + 5;
int d[maxn], V[maxn], n;

// 调用前需要memset(dp, -1, sizeof(dp))
int dp(int S){
    int& ans = d[S];
    if(ans != -1) return ans;
    ans = -(1 << 30);
    for(int i = 1; i <= n; i++)
        if(S >= V[i]) ans = max(ans, dp(S-V[i]) + 1);
    return ans;
}

int dp_2(int S){
    int minv[S], maxv[S];
    minv[0] = maxv[0] = 0;
    for(int i = 1; i <= S; i++){    
        minv[i] = INF; maxv[i] = -(INF);
    }
    for(int i = 1; i <= S; i++)
        for(int j = 1; j <= n; j++)
            if(i >= V[j]){
                minv[i] = min(minv[i], minv[i - V[j]] + 1);
                maxv[i] = max(maxv[i], maxv[i - V[j]] + 1);
            }
    printf("%d %d\n", minv[S], maxv[S]);
}

// 输出字典序最小方案
void print_ans(int* d, int S){
    for(int i = 1; i <= n; i++)
        if(S >= V[i] && d[S] == d[S - V[i]] + 1){
            printf("%d ", i);
            print_ans(d, S - V[i]);
            break;
        }
}

void print_ans_2(int S, int* minv, int* maxv){

    for(int i = 1; i <= S; i++)
        for(int j = 1; j <= n; j++)
            if(i >= V[j]){
                if(minv[i] > minv[i - V[j]] + 1){
                minv[i] = minv[i - V[j]] + 1;
                min_coin[i] = j
                }
            }
}

int main(){


    return 0;
}