#include <cstdio>
#include <cstring>
#include <iostream>
// G是DAG的邻接矩阵，d[i]是从i点出发的最长路径长度
int G[100][100], d[100], n;
int dp(int i){
    int& ans = d[i];
    if(ans > 0) return ans;
    ans = 1;
    for(int j = 1; j <= n; j++)
        if(G[i][j]) ans = std::max(ans, dp(j) + 1);
    return ans;
}

void print_ans(int i){
    printf("%d ", i);
    for(int j = 1; j <= n; j++)
        if(G[i][j] && d[i] == d[j] + 1){ // 按字典序输出结果，找到从i出发最长(就是比d[i]小1)且最小的j
            print_ans(j); // 递归打印从j开始的字典序最小且最优的路径
            break; // 找到j后就应该跳出循环，不然有更大的j即使路径长度一样，字典序却大了
        }
}

int main(){
    memset(d, 0, sizeof(d));
    int mx = dp(1);
    int ans = 1;
    for(int i = 2; i <= n; i++) // 找到从哪个起点开始的最长路径最长
        if(dp(i) > mx){
            mx = dp(i);
            ans = i;
        }
    printf("Start from node %d has the longest path whose length = %d\n", ans, mx);
    return 0;
}