#include <cstdio>
#include <cstring>
char chess[9][9];
int n, k, C, vis[9];
void search(int row, int leftk){
    if(leftk == 0) { C++; return; }
    else if(row == n + 1 || n - row + 1 < leftk) {return ;}
    for(int i = 1; i <= n; i++){// 要在这行放棋子
        if(!vis[i] && chess[row][i] == '#'){
            vis[i] = 1;
            search(row+1, leftk-1); 
            vis[i] = 0;
        }
    }
    search(row+1, leftk); // 不在这行放棋子，直接跳到下一行

}

int main(){
    while(scanf("%d%d", &n, &k) == 2 && n != -1){
        memset(vis, 0, sizeof(vis));
        C = 0;
        for(int i = 1; i <= n; i++)
            scanf("%s", chess[i]+1);
        search(1, k);
        printf("%d\n", C);
    }

    return 0;
}