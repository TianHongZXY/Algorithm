#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 5e5 + 10;
int fa[maxn], vis[maxn], A, B, fangwen[maxn];
vector<int> child[maxn]; // samefa[i]包含node i的所有子节点

int compute_beauty(int as, int bs){
    int cnt = 0;
    while(as){
        if(!vis[as]){
            vis[as] = 1; cnt++;
        }
        for(int i = 0; i < A; i++){
            as = fa[as];
        }
    }
    while(bs){
        if(!vis[bs]){
            vis[bs] = 1; cnt++;
        }
        for(int i = 0; i < B; i++){
            bs = fa[bs];
        }
    }
    return cnt;
}

int main(){
    int T, N;
    scanf("%d", &T);
    for(int c = 1; c <= T; c++){
        scanf("%d%d%d", &N, &A, &B);
        fa[1] = 0;
        child[0].push_back(1);
        for(int i = 2; i <= N; i++){
            scanf("%d", &fa[i]);
            child[fa[i]].push_back(i);
        }
        int ans = 0;
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(fa[i] == fa[j]){
                    if(fangwen[fa[i]]) continue;
                    else{
                        int same = compute_beauty(i, j);
                        memset(vis, 0, sizeof(vis));
                        int diff = 0;
                        if(child[fa[i]].size() > 1){
                            diff = compute_beauty(child[fa[i]][0], child[fa[i]][1]);
                            memset(vis, 0, sizeof(vis));
                        }
                        ans += same * child[fa[i]].size();
                        ans += diff * (child[fa[i]].size() * (child[fa[i]].size() - 1));
                        fangwen[fa[i]] = 1;
                        continue;
                    }
                }
                ans += compute_beauty(i, j);
                memset(vis, 0, sizeof(vis));
            }
        }
        printf("Case #%d: %.6f\n", c, 1.0 * ans / (N * N));
        // for(int i = 0; i < N; i++){
        //     child[i].clear();
        //     child[i].shrink_to_fit();
        // }
        memset(fangwen, 0, sizeof(fangwen));
    }
    return 0;
}