#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <iostream>
#include <set>
using namespace std;
const int maxn = 30;
const int maxm = maxn * maxn;
int d[maxn][maxn];
int vis[maxn], appear[maxn];
int n, m, T = 1;
map<int, string> idx2name;
map<string, int> name2idx;

void init(){
    memset(d, 0, sizeof(d));
    memset(vis, 0, sizeof(vis));
    memset(appear, 0, sizeof(appear));
    idx2name.clear();
    name2idx.clear();
    for(int i = 0; i < n; i++)
        d[i][i] = 1;
}

void floyd(){
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                d[i][j] = (d[i][j] || (d[i][k] && d[k][j]));
}

void solve(){
    printf("Calling circles for data set %d:\n", T++);
    for(int i = 0; i < n; i++){
        if(!appear[i]) continue;
        if(!vis[i]) { cout << idx2name[i]; vis[i] = 1; }
        else continue;
        for(int j = 0; j < n; j++){
            if(vis[j]) continue;
            if(d[i][j] && d[j][i]){
                vis[j] = 1;
                cout << ", " << idx2name[j];
            }
        }
        printf("\n");
    }
    return;
}

int main(){
    string x, y;
    while(scanf("%d%d", &n, &m) == 2 && n){
        if(T != 1) printf("\n");
        int idx = 0;
        init();
        for(int i = 0; i < m; i++){
            cin >> x >> y;
            if(!name2idx.count(x)) { name2idx[x] = idx; idx2name[idx++] = x; }
            if(!name2idx.count(y)) { name2idx[y] = idx; idx2name[idx++] = y; }
            int xidx = name2idx[x], yidx = name2idx[y];
            d[xidx][yidx] = 1;
            appear[xidx] = appear[yidx] = 1;
        }
        floyd();
        solve();
    }
    return 0;
}