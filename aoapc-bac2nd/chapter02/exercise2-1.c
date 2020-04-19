//
// Created by TianHongZXY on 2020/3/13.
//
#include <stdio.h>
#include <math.h>

int main(){
    for (int abc = 100; abc <= 999; abc++){
        int A = abc / 100;
        int B = abc % 100 / 10;
        int C = abc % 10;
        if (pow(A, 3) + pow(B, 3) + pow(C, 3) == abc)
            printf("%d %d %d\n", A, B, C);
    }
    return 0;
}
