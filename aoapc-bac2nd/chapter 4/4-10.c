//
// Created by TianHongZXY on 2020/3/21.
//
#include <stdio.h>

int f(int n){
    return n == 0 ? 1 : f(n - 1) * n;
}

int main(){
    printf("3! = %d\n", f(100000000));
    return 0;
}
