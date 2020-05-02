#include <cstdio>
#include <cstring>
int tot, n;
int C[100];
int vis[3][100];

void search(int cur){
    if(cur == n) tot++;
    else for (int i = 0; i < n; i++){
        int ok = 1;
        C[cur] = i; // 第cur行第i列放置一个皇后
        for(int j = 0; j < cur; j++)
            // 列坐标 - 行坐标 同一对角线相等，列坐标 + 行坐标 同一反对角线相等
            if(C[cur] == C[j] || C[cur] - cur == C[j] - j || C[cur] + cur == C[j] + j){
                ok = 0; break;
            }
            if (ok) search(cur + 1);
    }
}

void search_2(int cur){
    if(cur == n) tot++;
    else for (int i = 0; i < n; i++){
        // 分别代表第i列，反对角线，主对角线是否被占用
        if(!vis[0][i] && !vis[1][cur+i] && !vis[2][cur-i+n]){
            C[cur] = i;
            vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = 1;

            search_2(cur+1);
            // 退出回溯后，释放占用
            vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = 0;
        }
        
    }
}

int main(){
    scanf("%d", &n);
    search(0);
    printf("The %d queens question has %d solutions.\n", n, tot);
    

    tot = 0; memset(C, 0, sizeof(C)); memset(vis, 0, sizeof(vis));
    search_2(0);
    printf("The %d queens question has %d solutions.\n", n, tot);
    return 0;
}