#include <cstdio>

int abs(int a){
    return (a >= 0 ? a : -a);
}

void swap(int a[], int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void sort(int a[], int n){
    for(int i = 0; i < n; i++)
        for(int j = n - 1; j >= i + 1; j--){
            if(abs(a[j]) > abs(a[j - 1])) swap(a, j, j - 1);
        }
}

int main(){
    int n, a[100 + 10];
    while(scanf("%d", &n) == 1 && n){
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        sort(a, n);
        int first = 1;
        for(int i = 0; i < n; i++)
            if(first) { printf("%d", a[i]); first = 0; }
            else printf(" %d", a[i]);
        printf("\n");
    }

    return 0;
}