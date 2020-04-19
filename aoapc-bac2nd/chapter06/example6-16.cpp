#include <bits/stdc++.h>
using namespace std;
const int maxn = 26;
int G[maxn][maxn];
int degree[maxn];
int visited[maxn];
set<int> alphas;

void dfs(int x){
    if(!visited[x]){
        visited[x] = 1;
        for(auto j: alphas)
            if(G[x][j] && !visited[j])
                dfs(j);
    }
}

int main(){
    int T, n;
    scanf("%d", &T);
    string word;
    while(T--){
        memset(G, 0, sizeof(G));
        memset(degree, 0, sizeof(degree));
        memset(visited, 0, sizeof(visited));
        alphas.clear();
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            cin >> word;
            int start = word[0] - 'a', end = word.back() - 'a'; // 首尾字母的index
            alphas.insert(start); alphas.insert(end); // 插入set，防重复
            G[start][end] = 1; G[end][start] = 1; // 无向图
            degree[start]--; degree[end]++; // 出--，入++
        }
        dfs(*(alphas.begin())); // 从任一开始点进行dfs，遍历得到visited
        if (alphas.size() != accumulate(visited, visited+maxn, 0)){ // 判断字母总数和被访问总数是否相等，如果有字母没被dfs访问到，则不连通
            cout << "The door cannot be opened." << endl;
            continue;
        }
        int even = 0, start = -1, end = -1;
        for(auto i: alphas){
            if(degree[i] == 0) even++;
            else if(degree[i] == 1 && end == -1) // 入度大于出度则为终点，且只能有一个终点
                end = i;
            else if(degree[i] == -1 && start == -1) // 出度大于入则为起点，且只能有一个起点
                start = i;
            else {even = start = end = -1; break;} // 都不符合，打破循环
        }
        if(even == alphas.size() || (even == alphas.size() - 2 && start != -1 && end != -1)) cout << "Ordering is possible." << endl;
        else cout << "The door cannot be opened." << endl;
    }
    return 0;
}