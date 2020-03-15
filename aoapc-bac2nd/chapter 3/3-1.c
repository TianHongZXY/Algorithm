//
// Created by TianHongZXY on 2020/3/13.
//
#include <stdio.h>
#include <string.h>
// 如果a定义在main函数里，maxn很大时程序就会异常退出
#define maxn 105
int a[maxn];

void example3_2(){
    int e32[1010];
    int n, k, first = 1;
    scanf("%d%d", &n, &k);
    memset(e32, 0, sizeof(int) * (n+1));
    for(int i = 1; i <= k; i++){
        for (int j = i; j <= n; j += i){
            e32[j] = !e32[j];
        }
    }
    for (int i = 1; i <= n; i++){
        if (e32[i]) {
            if (first)
                first = 0;
            else
                printf(" ");
            printf("%d", i);
        }
    }
}

void example3_3(){
    int e33[20][20];
    int n, x, y, tot = 0;
    scanf("%d", &n);
    memset(e33, 0, sizeof(e33));
    tot = e33[x=0][y=n-1] = 1;
    while(tot < n * n){
        while(x + 1 <= n - 1 && !e33[x + 1][y]) e33[++x][y] = ++tot;
        while(y - 1 >= 0 && !e33[x][y - 1]) e33[x][--y] = ++tot;
        while(x - 1 >= 0 && !e33[x - 1][y]) e33[--x][y] = ++tot;
        while(y + 1 <= n - 1 && !e33[x][y + 1]) e33[x][++y] = ++tot;
    }
    for (x = 0; x < n; x++) {
        for (y = 0; y < n; y++)
            printf("%4d", e33[x][y]);
        printf("\n");
    }
}


int main(){
//    int x, n = 0;
//    while (scanf("%d", &x) == 1)
//        if (x == -1) break;
//        else a[n++] = x;
//    for (int i = n - 1; i >= 1; i--)
//        printf("%d ", a[i]);
//    printf("%d\n", a[0]);

    int b[10];
    memcpy(b, a, sizeof(int) * 10);
    memcpy(b, a, sizeof(b));
    example3_2();
    example3_3();
    return 0;
}