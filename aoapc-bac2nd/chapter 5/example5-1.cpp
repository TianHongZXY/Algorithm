//
// Created by TianHongZXY on 2020/3/25.
//
#include <iostream>
#include <cstdio>
#include <algorithm>
const int maxn = 10000 + 5;
using namespace std;
int main(){
    int n, q, x, kase = 0;;
    int a[maxn];
    while(scanf("%d%d", &n, &q) == 2 && n){
        printf("CASE# %d:\n", ++kase);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a+n);
        while(q--){
            scanf("%d", &x);
            int p = lower_bound(a, a+n, x) - a;
            if(a[p] == x) printf("%d found at %d\n", x, p+1);
            else printf("%d not found\n", x);
        }
    }
}