// 原博客链接 https://blog.csdn.net/yandaoqiusheng/article/details/84782655
#include <iostream>
using namespace std;
const int maxn = 1e3;
int w[maxn], v[maxn], f[maxn];
int N, V;

void version1(){
    // 基本思路，f[i][j] = max(f[i − 1][j − k * w[i]] + k * v[i]) for k : 0 <= k * w[i] <=j
    // 优化1：若两件物品i、j满足w[i] <= w[j] 且v[i] >= v[j]，则将物品j去掉
    // 优化2：将费用大于V的物品去掉
}

void version2(){
    // 转为01背包求解，第i种物品最多选V/w[i]件，可以把第i种物品转化为V/w[i]件费用及价值均不变的物品，然后求解这个01背包问题
    // 改进：把第i种物品拆成费用为w[i]*2^k，价值为v[i]*2^k的物品，其中k满足w[i]*2^k <= V，每个k对应一件。
    // 这是二进制的思想，因为假设最优策略选x件第i种物品，x总可以表示成 x = sum(2^k) (for k = 0,1,2...)。
    // 这样把每种物品拆成 log(V/w[i])件物品，是一个很大的改进。
}

void version3(){
    // 复杂度O(VN)的算法，f[i][j] = max(f[i − 1][j], f[i][j − w[i]] + v[i])
    for (int i = 1; i <= N; i++)
        for (int j = w[i]; j <= V; j++)
            f[j] = max(f[j], f[j - w[i]] + v[i]);
}

