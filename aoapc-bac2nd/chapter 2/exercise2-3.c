//
// Created by TianHongZXY on 2020/3/13.
//

#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    if (n < 1) return -1;
    int len = 2 * n - 1;
    for (int i = 0; i < n; i++){
        for (int k = 0; k < i; k++)
            printf(" ");
        for (int j = 0; j < len; j++)
            printf("#");
        for (int k = 0; k <= i; k++)
            printf(" ");
        printf("\n");
        len -= 2;
    }
    return 0;
}