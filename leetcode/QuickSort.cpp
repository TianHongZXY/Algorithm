//
// Created by TianHongZXY on 2020/4/14.
//
#include <algorithm>
#include <random>
#include <iostream>
using namespace std;

int partition(int a[], int lo, int hi){
    int i = lo, j = hi + 1;
    int v = a[lo];
    while(true){
        while(a[++i] < v) if(i == hi) break;
        while(a[--j] > v) if(j == lo) break;
        if (i >= j) break;
        swap(a[i], a[j]);
    }
    // 最终跳出循环时j是小于等于v的，所以把j和开头的v交换
    swap(a[lo], a[j]);
    return j;
}

void sort(int a[], int lo, int hi){
    if (hi <= lo) return;
    shuffle(a+lo, a+hi+1, default_random_engine(20020206+19990303));
    int j = partition(a, lo, hi);
    sort(a, lo, j - 1);
    sort(a, j + 1, hi);
}

int main(){
    int a[] = {32,435,132,45,67,21,44,6,7899,6,5,43,21};
    int n = sizeof(a) / sizeof(a[0]);
    sort(a, 0, n-1);
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}