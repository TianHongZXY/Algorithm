//
// Created by TianHongZXY on 2020/3/19.
//
#include <stdio.h>
#include <math.h>
int is_prime(int n){
    if(n <= 1) return 0;
    int m = floor(sqrt(n) + 0.5);
    for(int i = 2; i <= m; i++){
        if(n % i == 0) {printf("%d\n", i); return 0;}
    }
    return 1;
}

int main(){
    int n = 2143253;
    int isp = is_prime(n);
    printf("%d\n", isp);
    return 0;
}