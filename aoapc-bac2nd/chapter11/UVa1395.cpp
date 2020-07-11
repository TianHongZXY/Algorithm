#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 1e2 + 5;
const int maxm = 5e3 + 5;
int n, m;
int u[maxm], v[maxm], w[maxm], p[maxn], r[maxm];

int cmp(const int i, const int j) { return w[i] < w[j]; }
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
void init(){
    for(int i = 1; i <= n; i++) p[i] = i;
}

int main(){
    while(scanf("%d%d", &n, &m) == 2 && n){
        for(int i = 1; i <= m; i++)
            scanf("%d%d%d", &u[i], &v[i], &w[i]);
        if(m < n - 1){
            printf("-1\n"); continue;
        }
        for(int i = 1; i <= m; i++) r[i] = i;
        sort(r + 1, r + m + 1, cmp);
        int ans = INF, x;
        for(int i = 1; i <= m; i++){
            init(); // 初始化
            int cnt = n; // 一开始每个点都自成一个集合
            for(int j = i; j <= m; j++){
                int x = find(u[r[j]]); int y = find(v[r[j]]);
                if(x != y){
                    p[x] = y; // 合并两个点所属于的集合
                    if(--cnt == 1) { ans = min(ans, w[r[j]] - w[r[i]]); break; } // 只剩一个集合了，这就是生成树
                }
            }
        }
        printf("%d\n", ans == INF ? -1 : ans);
    }
    return 0;
}