//
// Created by TianHongZXY on 2020/4/14.
//
#include <iostream>
using namespace std;
void sort(int a[], int n){
    for(int i = 1; i < n; i++){
        for(int j = i; j > 0 && a[j-1] > a[j]; j--)
            swap(a[j-1], a[j]);
    }
}

int main(){
    int a[] = {32,435,132,45,67,21,44,6,7899,6,5,43,21};
    int n = sizeof(a) / sizeof(a[0]);
    sort(a, n);
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}
