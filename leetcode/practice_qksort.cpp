#include <cstdio>
#include <iostream>
using namespace std;
int partition(int a[], int lo, int hi){
    int pivot = a[lo];
    int i = lo, j = hi + 1;
    while(true){
        while(a[++i] < pivot) if (i >= hi) break;
        while(a[--j] > pivot) if (j <= lo) break;
        if(i >= j) break;
        swap(a[i], a[j]);
    }
    swap(a[lo], a[j]);
    return j;
}

void sort(int a[], int lo, int hi){
    if(lo >= hi) return;
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