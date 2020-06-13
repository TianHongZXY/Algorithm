#include <cstdio>
#include <iostream>
using namespace std;

void sort(int a[], int n){
    for(int i = 0; i < n; i++)
    
        for(int j = 1; j < n - i; j++){
            if(a[j - 1] > a[j])
                swap(a[j - 1], a[j]);
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