//
// Created by TianHongZXY on 2020/4/14.
//
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100 + 5;
const int maxm = 100 + 5;
char oil[maxm][maxn];
int m, n;

void dfs(int x, int y){
    oil[x][y] = '*';
    int nx, ny;
    for(int dx = -1; dx <= 1; dx++)
        for(int dy = -1; dy <= 1; dy++){
            nx = x + dx; ny = y + dy;
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && oil[nx][ny] == '@')
                dfs(nx, ny);
        }
}

int main(){
    while(scanf("%d%d", &m, &n) == 2 && m != 0){
        getchar();
        int res = 0;
        for(int i = 0; i < m; i++){
            cin.getline(oil[i], n+1);
        }
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(oil[i][j] == '@'){
                dfs(i, j);
                res++;
            }
        printf("%d\n", res);
    }
}