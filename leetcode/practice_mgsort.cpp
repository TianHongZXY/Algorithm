#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 100000;
int res[maxn];

void merge(int a[], int lo, int hi, int mid){
    if(a[mid] < a[mid + 1]) return;
    int i = lo, j = mid + 1;
    for(int k = lo; k <= hi; k++){
        res[k] = a[k];
    }
    for(int k = lo; k <= hi; k++){
        if(i > mid) a[k] = res[j++];
        else if (j > hi) a[k] = res[i++];
        else if(res[i] < res[j]) a[k] = res[i++];
        else a[k] = res[j++];
    }
}

void sort(int a[], int lo, int hi){
     if(lo >= hi) return;
     int mid = lo + (hi - lo) / 2;
     sort(a, lo, mid);
     sort(a, mid + 1, hi);
     merge(a, lo, hi, mid);
}

int main(){
    int a[] = {32,435,132,45,67,21,44,6,7899,6,5,43,21};
    int n = sizeof(a) / sizeof(a[0]);
    sort(a, 0, n-1);
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}