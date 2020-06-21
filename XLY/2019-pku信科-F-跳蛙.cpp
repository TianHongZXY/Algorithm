// 没看出规律 用的康拓展开+BFS搜索，花费了大量时间，没想到找规律一下就能解出来。。。
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
typedef char State[11];
const int maxs = 1e5;
int n, found;
int fac[10];
int vis[maxs];
State ss[maxs];
State s;

void set_fac(){
    fac[0]=1;
    for(int i=1;i<=9;i++)
        fac[i] = fac[i - 1] * i;
}
int cantor(State s){
    int ans = 0;
    for(int i = 0; i < n; i++){
        int k = 0;
        for(int j = i + 1; j < n; j++){
            if(s[i] > s[j]) k++;
        }
        ans += k * fac[9 - (10 - n) - i];
    }
    return ans;
}

void print(State x){
    for(int i = 0; i < n; i++) printf("%c", x[i] == '.' + 'A' ? '.' : x[i]);
    printf("\n");
    return;
}

bool try_to_insert(State x, int cofx){
    if(!vis[cofx]){
        vis[cofx] = 1;
        memcpy(ss[cofx], x, sizeof(ss[cofx]));
        return true;
    }
    return false;
}

void bfs(){
    queue<int> Q;
    int cofs = cantor(s);
    vis[cofs] = 1;
    memcpy(ss[cofs], s, sizeof(ss[cofs]));
    Q.push(cofs);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
//        if(cur == 360){
//            print(ss[cur]);
//            printf(" %d", cantor(ss[cur]));
//        }
        if(ss[cur][n - 1] == 'A'){
            printf("Y\n"); found = 1; break;
        }
        State x; memcpy(x, ss[cur], sizeof(x));
        for(int i = 0; i < n; i++){
            if(x[i] == 'A'){
                int swaped = 0, j;
                if(i - 1 >= 0 && x[i - 1] == 'B'){
                    for(j = i - 2; j >= 0; j--){
                        if(x[j] == '.' + 'A'){ swap(x[j], x[i]); swaped = 1; break; }
                    }
                    if(swaped){
                        int cofx = cantor(x);
                        if(try_to_insert(x, cofx)){
                            Q.push(cofx);
                            if(x[n - 1] == 'A') {found = 1; return; }
//                            printf("%d ", cofx);
//                            print(x);
                        }
                        swap(x[j], x[i]); // 还原
                        swaped = 0;
                    }
                }
                if(i + 1 < n && x[i + 1] == 'B'){
                    for(j = i + 2; j < n; j++){
                        if(x[j] == '.' + 'A') { swap(x[j], x[i]); swaped = 1; break; }
                    }
                    if(swaped){
                        int cofx = cantor(x);
                        if(try_to_insert(x, cofx)){
                            Q.push(cofx);
                            if(x[n - 1] == 'A') {found = 1; return; }
//                            printf("%d ", cofx);
//                            print(x);
                        }
                        swap(x[j], x[i]); // 还原
                    }
                }
            }
            else if(x[i] == 'B'){
                if(i - 1 >= 0 && x[i - 1] == '.' + 'A'){
                    swap(x[i], x[i - 1]);
                    int cofx = cantor(x);
                    if(try_to_insert(x, cofx)) {
                        Q.push(cofx);
//                        printf("%d ", cofx);
//                        print(x);
                    }
                    swap(x[i], x[i - 1]);
                }
                if(i + 1 < n && x[i + 1] == '.' + 'A'){
                    swap(x[i], x[i + 1]);
                    int cofx = cantor(x);
                    if(try_to_insert(x, cofx)){
//                        printf("%d ", cofx);
//                        print(x);
                        Q.push(cofx);
                    }
                    swap(x[i], x[i + 1]);
                }

            }
        }
    }
}

int main(){
    set_fac();
    while(scanf("%d", &n) == 1 && n){
        scanf("%s", s);
        for(int i = 0; i < n; i++){
            if(s[i] == '.') s[i] += 'A';
        }
        found = 0;
        bfs();
        if(!found) printf("N\n");
        else printf("Y\n");
        memset(vis, 0, sizeof(vis));
    }

    return 0;
}