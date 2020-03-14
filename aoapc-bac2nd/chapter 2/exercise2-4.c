//
// Created by TianHongZXY on 2020/3/13.
//
#include <stdio.h>

int main(){
    int n, m;
    while(1){
        scanf("%d%d", &n, &m);
        if (n == 0 && m == 0) break;
        double sum = 0;
//      应该是因为i * i过大会导致整数溢出，所以这里i用double表示
        for (double i = n; i <= m; i++){
//            printf("%.20lf", 1.0 / (i * i));
            sum += 1.0 / (i * i);
        }
        printf("%.5f\n", sum);
    }
    return 0;
}