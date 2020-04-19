//
// Created by TianHongZXY on 2020/3/21.
//
#include <stdio.h>
#define maxn 25

int n, k, m, a[maxn];

int go(int p, int d, int t){
    while(t--){
//      当方向d为正数时，p + d + n - 1 = p + n
//      故p = (p + n) % n + 1，向前走一步p在（1，n）范围
//      当d为负数时，p + d + n - 1 = p + n - 2
//      p = (p + n - 2) % n + 1 = p - 2 + 1 = p - 1，向后走一步p范围在（1，n）
        do {p = (p + d + n - 1) % n + 1;} while(a[p] == 0);
    }
    return p;
}

int main(){
    while(scanf("%d%d%d", &n, &k, &m) == 3 && n){
        for(int i = 1; i <= n; i++) a[i] = i;
//      我们传递到处理函数中的位置初值，应该是我们开始处理的前一个数据。
//      我们返回应该处理的数据的位置
        int p1 = n; int p2 = 1;
        int left = n;
        while(left){
            p1 = go(p1, 1, k);
            p2 = go(p2, -1,  m);
            printf("%3d", p1);
            a[p2] = a[p1] = 0;
            left--;
            if (p1 != p2) {printf("%3d", p2); left--;}
            if(left) printf(",");
        }
        printf("\n");
    }
    return 0;
}