#include <cstdio>
#include <cstring>
#include <cmath>
int A[20], vis[20];
bool isp[32];
int n;

bool is_prime(int i){
    for(int j = 2; j <= (int)round(sqrt((double)i)); j++){
        if (i % j == 0) return false;
    }
    return true;
}

void dfs(int cur){
    if(cur == n && isp[A[0] + A[n-1]]){
        printf("%d", A[0]);
        for(int i = 1; i < n; i++) printf(" %d", A[i]);
        printf("\n");
    }
    else for(int i = 2; i <= n; i++){
        if(!vis[i] && isp[i+A[cur-1]]){
            A[cur] = i;
            vis[i] = 1;
            dfs(cur+1);
            vis[i] = 0;
        }
    }
}

int main(){
    int kase = 0;
    for(int i = 0; i < 32; i++) isp[i] = is_prime(i);
    A[0] = 1;
    while(scanf("%d", &n)==1 && n){
        if(kase) printf("\n");
        printf("Case %d:\n", ++kase);
        memset(vis, 0, sizeof(vis)); memset(A+1, 0, sizeof(A)-1);
        dfs(1);
    }
    return 0;
}