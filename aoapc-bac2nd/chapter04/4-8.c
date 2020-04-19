//
// Created by TianHongZXY on 2020/3/19.
//
#include <stdio.h>

int sum(int *a, int n){
    int res = 0;
    for(int i = 0; i < n; i++)
        res += a[i];
    return res;
}

int sum_2(int *begin, int *end){
//  对index属于[begin, end)的元素求和返回
    int n = end - begin;
    int res = 0;
    for(int i = 0; i < n; i++)
        res += begin[i];
    return res;
}

int sum_3(int *begin, int *end){
    int res = 0;
    for(int *p = begin; p != end; p++)
        res += *p;
    return res;
}

int main(){
    int a[] = {1, 2, 3, 4};
    printf("%d\n", sum(a, 4));
    printf("%d\n", sum(a + 1, 3));
    printf("%d\n", sum_2(a + 1, a + 4));
    printf("%d\n", sum_3(a + 1, a + 4));

    return 0;
}
