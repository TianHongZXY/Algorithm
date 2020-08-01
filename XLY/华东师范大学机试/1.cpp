#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
int prim[20];
set<int> st;
vector<int> yinshu;
const int maxn = 1e8 + 10;
int vis[maxn];
int notprim[maxn];
int nextt[maxn];

void init(){
    notprim[0] = notprim[1] = true;
    for(int i = 2; i <= maxn - 10; i++){
        if(!notprim[i]){
            if(i > (maxn - 10) / i) continue;
            for(int j = i * i; j <= maxn - 10; j += i)
                notprim[i] = 1;
        }
    //     for(int j = 2; j <= round(sqrt(i)); j++){
    //         if(i % j == 0) { notprim[i] = 1; break; }
    //     }
    // }
    }
    return;
}

bool dfs(int cur, int idx, int preidx){
    if(idx == yinshu.size()) return true;
    for(int i = 0; i < yinshu.size(); i++){
        if(!vis[i]){
            if(max(cur, yinshu[i]) % min(cur, yinshu[i]) == 0 && st.count(max(cur, yinshu[i]) / min(cur, yinshu[i]))){
                vis[i] = 1;
                nextt[preidx] = i;
                if(dfs(yinshu[i], idx+1, i)) return true;
                nextt[preidx] = -1;
                vis[i] = 0;
            }
        }
    }
    return false;
}

int main(){
    // init();
    int n, p, k, a = 1;
    memset(nextt, -1, sizeof(nextt));
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &prim[i], &k);
        st.insert(prim[i]);
        a *= pow(prim[i], k);
    }
    for(int i = 1; i <= a; i++){
        if(a % i == 0) yinshu.push_back(i);
    }
    int ans;
    for(int i = 0; i < yinshu.size(); i++){
        vis[i] = 1;
        if(dfs(yinshu[i], 1, i)) { ans = i; break; }
        vis[i] = 0;
    }
    // vector<int> res;
    while(ans != -1){
        printf("%d\n", yinshu[ans]);
        ans = nextt[ans];
    }
    return 0;
}