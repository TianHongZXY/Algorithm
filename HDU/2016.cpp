#include <cstdio>
#define INF (1<<30)

void swap(int a[], int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int main(){
    int n, cache[100+10];
    while(scanf("%d", &n) == 1 && n){
        int min = INF, minidx = -1;
        for(int i = 0; i < n; i++){
            scanf("%d", &cache[i]);
            if(cache[i] < min){ min = cache[i]; minidx = i; }
        }
        swap(cache, 0, minidx);
        for(int i = 0; i < n - 1; i++) printf("%d ", cache[i]);
        printf("%d\n", cache[n-1]);
    }

    return 0;
}