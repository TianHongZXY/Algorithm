//
// Created by TianHongZXY on 2020/3/13.
//
#include <stdio.h>

int main(){
    int a, b, c, kase = 0;
    while(1){
        scanf("%d%d%d", &a, &b, &c);
        if (a == 0 && b == 0 && c == 0) break;
        if (a >= 1000000 || b >= 1000000){
            printf("a or b is too big!\n");
            continue;
        }
        double res = (double)a / b;
        printf("Case %d: %.*f", ++kase, c, res);
    }

    return 0;
}