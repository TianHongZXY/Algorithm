#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 200;
int dp[maxn];
struct node{
    int l, r, w;
    bool operator < (const node& rhs){
        if(rhs.l == l) return r < rhs.r;
        return l < rhs.l;
    }
    node(int a, int b, int c){ l = a; r = b; w = c;}
    node(){}
}blocks[maxn];

int main(){
    int n, kase = 0, l, r, w;
    while(scanf("%d", &n) == 1 && n){
        int nums = 0;
        for(int i = 0; i < n; i++){
            scanf("%d%d%d", &l, &r, &w);
            blocks[nums++] = node(l, r, w);
            blocks[nums++] = node(l, w, r);
            blocks[nums++] = node(r, l, w);
            blocks[nums++] = node(r, w, l);
            blocks[nums++] = node(w, l, r);
            blocks[nums++] = node(w, r, l);
        }
        memset(dp, 0, sizeof(dp));
        sort(blocks, blocks+nums);
        int ans = -1;
        for(int i = 0; i < nums; i++){
            dp[i] = blocks[i].w;
            for(int j = i - 1; j >= 0; j--){
                if(blocks[j].l < blocks[i].l && blocks[j].r < blocks[i].r){
                    dp[i] = max(dp[i], dp[j] + blocks[i].w);
                }
            }
            ans = max(ans, dp[i]);
        }
        printf("Case %d: maximum height = %d\n", ++kase, ans);

    }

    return 0;
}