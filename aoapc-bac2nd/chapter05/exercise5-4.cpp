//
// Created by TianHongZXY on 2020/4/1.
//
#include <bits/stdc++.h>
using namespace std;
const int maxn = 500000 + 10;
int loc[maxn];
int tgt[maxn];

int main(){
    int n;
    while(scanf("%d", &n) == 1 && n){
        for(int i = 0; i < n; i++){
            scanf("%d%d", &loc[i], &tgt[i]);
        }
        sort(loc, loc+n);
        sort(tgt, tgt+n);
        bool same = true;
        for(int i = 0; i < n; i++){
            if (loc[i] != tgt[i]){
                printf("NO\n");
                same = false;
                break;
            }
        }
        if (same) printf("YES\n");
    }
    return 0;
}

/* 网上更好的解法
 * 题意：判断第一列的数字是否与第二列的数字相同（乱序）。解题方向多样，值得探究：
 * 1、map哈希表解法：定义map<int, int> cnt;，其中cnt[i]表示学校i对应的人数增减变化量，
 * 若有人把学校i作为出发地，则cnt[i]--；若作为目的地，则cnt[i]++。
 * 最终若是每个学校变化量均为0，说明项目可行；否则不可行。
 * 特点：时间、空间复杂度皆为O(n)，都是动态开辟，基数小。为上等解法。
 */