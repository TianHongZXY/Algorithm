// 原博客链接 https://blog.csdn.net/yandaoqiusheng/article/details/84782655
#include <iostream>
using namespace std;
const int maxn = 1e3;
int w[maxn], v[maxn], f[maxn], p[maxn];
int N, V, K;

void version1(){
    // 物品被划分为K组，每组中的物品互相冲突，最多选一件。
    // 这个问题变成了每组物品有若干种策略：是选择本组的某一件，还是一件都不选。
    // 也就是说设f[k][j]表示前k组物品花费费用j能取得的最大权值，则有：
    // f[k][j] = max(f[k − 1][j], f[k − 1][j − c[i]] + w[i])，物品i属于组k
    for(int k = 1; k <= K; k++) // 所有的组k
        for(int j = V; j >= 0; j--)
            for(所有属于组k的物品i) // 此处可以使用完全背包中的优化方法
                f[j] = max(f[j], f[j - w[i]] + v[i]);


}