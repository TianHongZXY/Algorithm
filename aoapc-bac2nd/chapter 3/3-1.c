//
// Created by TianHongZXY on 2020/3/13.
//
#include <stdio.h>
// 如果a定义在main函数里，maxn很大时程序就会异常退出
#define maxn 105
int a[maxn];

int main(){
    int x, n = 0;
    while (scanf("%d", &x) == 1)
        a[n++] = x;
    for (int i = n - 1; i >= 1; i--)
        printf("%d ", a[i]);
    printf("%d\n", a[0]);

    int b[10];

    return 0;
}