#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1e3 + 10;
vector<int> G[maxn]; // G[u]包含u节点的所有邻居
int p[maxn]; // p[u]为u的父节点

void read_tree(){
    int u, v, n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

void dfs(int u, int fa){ // 把节点u的邻居都变成u的儿子，即让u成为它所有除了自身父节点以外的邻居们的父节点
    int d = G[u].size();
    for(int i = 0; i < d; i++){
        int v = G[u][i];
        if(v != fa) dfs(v, p[v] = u); // 如果该邻居不是u的父节点，对v的邻居做同样的事情
    }
}

int main(){
    int root;
    scanf("%d", &root);
    p[root] = -1;
    dfs(root, -1);
    
    return 0;
}