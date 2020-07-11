// 原博客链接 https://blog.csdn.net/yandaoqiusheng/article/details/84782655
#include <iostream>
using namespace std;
const int maxn = 1e3;
int w[maxn], v[maxn], f[maxn], p[maxn];
int N, V;

void version1(){ // 01背包与完全背包的混合
    // 外层循环到第i个物品时，如果该物品只能取一次，内层循环j反向，若是能取无限次的物品，正向循环
}

void version2(){ // version1再加上多重背包
    // 用多重背包中将每个物品分成p[i]个或O(log(p[i]))个01背包的物品的方法
    // p[i]代表每个物品的件数，0代表无穷个，这里用的是把多重背包拆成p[i]个物品的方法
    for(int i = 1; i <= N; i++){
        if(p[i] == 0){
            for(int j = w[i]; j <= V; j++)
                f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
        else{
            for(int k = 1; k <= p[i]; k++)
                for(int j = V; j >= w[i]; j--)
                    f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
    }
}

void version3(){
    // p[i]代表每个物品的件数，0代表无穷个，这里用的是把多重背包拆成O(log(p[i]))个物品的方法
    for(int i = 1; i <= N; i++){
        if(p[i] == 0){
            for(int j = w[i]; j <= V; j++)
                f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
        else{
            int num = min(V / w[i], p[i]);
            for(int k = 1; num > 0; k = k << 1){
                if(k > num) k = num;
                num -= k;
                for(int j = V; j >= w[i] * k; j--)
                    f[j] = max(f[j], f[j - w[i] * k] + k * v[i]);
            }
        }
    }
}

