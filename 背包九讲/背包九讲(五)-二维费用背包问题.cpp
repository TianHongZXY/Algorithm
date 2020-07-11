// 原博客链接 https://blog.csdn.net/yandaoqiusheng/article/details/84782655
#include <iostream>
using namespace std;
const int maxn = 1e3;
int w[maxn], g[maxn], v[maxn], f[maxn][maxn], p[maxn];
int N, V, T;

void version1(){
    for(int i = 1; i <= N; i++)
        for(int j = V; j >= w[i]; j--)
            for(int k = T; k >= g[i]; i--)
                f[j][k] = max(f[j][k], f[j - w[i]][k - g[i]] + v[i]);
}

// 有时，“二维费用”的条件是以这样一种隐含的方式给出的：最多只能取M件物品。
// 这事实上相当于每件物品多了一种“件数”的费用，每个物品的件数费用均为1，可以付出的最大件数费用为M。
// 换句话说，设f[i][j]表示付出费用i、最多选j件时可得到的最大价值，
// 则根据物品的类型（01、完全、多重）用不同的方法循环更新，最后在f[0...V][0...M]范围内寻找答案。