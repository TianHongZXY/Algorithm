#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
int tot, n;
int C[100];
int vis[3][100];

/* 是否可以在 board[row][col] 放置皇后？ */
bool isValid(vector<string>& board, int row, int col) {
    int n = board.size();
    // 检查列是否有皇后互相冲突
    for (int i = 0; i < n; i++) {
        if (board[i][col] == 'Q')
            return false;
    }
    // 检查右上方是否有皇后互相冲突
    for (int i = row - 1, j = col + 1; 
            i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q')
            return false;
    }
    // 检查左上方是否有皇后互相冲突
    for (int i = row - 1, j = col - 1;
            i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q')
            return false;
    }
    return true;
}

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