#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 100 + 10;
int a[maxn][maxn], d[maxn][maxn], n;

int solve1(int i, int j){
    // 递归计算
    return a[i][j] + (i == n ? 0 : max(solve1(i+1, j), solve1(i+1, j+1)));
}

int solve2(){
    // 递推计算
    for(int j = 1; j <= n; j++) d[n][j] = a[n][j];
    for(int i = n - 1; i >= 1; i--)
        for(int j = 1; j <= i; j++)
            d[i][j] = a[i][j] + max(d[i + 1][j], d[i + 1][j + 1]);
    return d[1][1];
}

int solve3(int i, int j){
    // 记忆化搜索，使用前要 memset d 为 -1
    if(d[i][j] >= 0) return d[i][j];
    return d[i][j] = a[i][j] + (i == n ? 0 : max(solve3(i + 1, j), solve3(i + 1, j + 1)));
}

int main(){
    memset(d, -1, sizeof(d));
}