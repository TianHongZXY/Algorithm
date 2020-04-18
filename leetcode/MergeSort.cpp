//
// Created by TianHongZXY on 2020/4/14.
//
#include <iostream>
using namespace std;
const int maxn = 10000;
int res[maxn];
// 原地归并
void merge(int a[], int lo, int mid, int hi){
    // 如果已经有序 跳过merge
    if(a[mid] <= a[mid+1]) return;
    int i = lo, j = mid + 1;
    for(int k = lo; k <= hi; k++)
        res[k] = a[k];
    for(int k = lo; k <= hi; k++)
        if(i > mid) a[k] = res[j++];
        else if (j > hi) a[k] = res[i++];
        else if (res[j] < res[i]) a[k] = res[j++];
        else a[k] = res[i++];
}

void sort(int a[], int lo, int hi){
    // 这里还可以设置如果要排序的长度小于某个阈值，直接用插入排序，整体速度能提升10%~15%
    if (hi <= lo) return;
    int mid = lo + (hi - lo) / 2;
    sort(a, lo, mid);
    sort(a, mid+1, hi);
    merge(a, lo, mid, hi);
}

int main(){
    int a[] = {32,435,132,45,67,21,44,6,7899,6,5,43,21};
    int n = sizeof(a) / sizeof(a[0]);
    sort(a, 0, n-1);
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}
