//
// Created by TianHongZXY on 2020/4/9.
//
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 256 + 10;
int left[maxn];
int right[maxn];
bool have_value[maxn];
int value[maxn];
int cnt;
int root = 0;
bool failed;

int newnode(){ int u = ++cnt; left[u] = 0; right[u] = 0; have_value[u] = false; return u;}

void newtree(){ root = 0; left[root] = right[root] = 0; have_value[root] = false; cnt = root;}

void addnode(int v, char *s){
    int n = strlen(s);
    int u = root;
    for(int i = 0; i < n - 1; i++) // 在这把最后一个字符')'去掉
        if(s[i] == 'L'){
            if(left[u] == 0) left[u] = newnode();
            u = left[u];
        }else if(s[i] == 'R'){
            if(right[u] == 0) right[u] = newnode();
            u = right[u];
        }
    if (have_value[u]) failed = true;
    value[u] = v;
    have_value[u] = true;
}

char s[maxn];

bool bfs(vector<int> &ans){
    queue<int> q;
    ans.clear();
    q.push(root);
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(!have_value[u]) return false;
        ans.push_back(value[u]);
        if(left[u] != 0) q.push(left[u]);
        if(right[u] != 0) q.push(right[u]);
    }
    return true;
}

bool read_input(){
    failed = false;
    newtree();
    while(1){
        if(scanf("%s", s) != 1) return false;
        if(strcmp(s, "()") == 0) break;
        int v;
        sscanf(&s[1], "%d", &v);
        addnode(v, strchr(s, ',')+1); // 这里把字符串最后一个括号也算进去了
    }
    return true;
}

int main(){
    vector<int> ans;
    while(read_input()){
        if(!failed && bfs(ans)) {
            int num = ans.size();
            for(int i = 0; i < num - 1; i++)
                printf("%d ", ans[i]);
            printf("%d\n", ans[num - 1]);
        }
        else
            printf("not complete\n");
    }

    return 0;
}
