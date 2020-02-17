#include <stdio.h>
#include <iostream>
using namespace std;

const int MAX_N = 100;
int L, n, a[MAX_N];

int solve(){
    int min_res = 0;
    int max_res = 0;
        for (int j = 0; j < n; j++){
            min_res = max(min_res, min(L-a[j], a[j]));
            max_res = max(max_res, max(L-a[j], a[j]));
        }
    printf("%d %d\n", min_res, max_res);
    return 0;
}
int main(){
    scanf("%d %d", &L, &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    solve();
}