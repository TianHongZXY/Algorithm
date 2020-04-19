//
// Created by TianHongZXY on 2020/3/19.
//
#include <stdio.h>
#include <string.h>
#define maxn 10000

long long F[maxn];

long long factorial(int n){
    long long m = 1;
    if(F[n]) return F[n];
    for(int i = 1; i <= n; i++){
        m *= i;
    }
    return F[n] = m;
}

long long C(int n, int m){
    if (n - m < 0){int t = m; m = n; n = t;}
//  有问题，n=21, m=1，中间计算结果就溢出了
    return factorial(n) / (factorial(m) * factorial(n - m));
}

long long C_correct(int n, int m){
    if (n - m > m) m = n - m;
    long long res = 1;
    for(int i = m + 1; i <= n; i++) res *= i;
    res /= factorial(n-m);
    return res;
}

int main(){
    memset(F, 0, sizeof(F));
    int n, m;
    scanf("%d%d", &n, &m);
    long long res = C(n, m);
    long long res_correct = C_correct(n, m);
    printf("%lld\n", res);
    printf("%lld\n", res_correct);

}