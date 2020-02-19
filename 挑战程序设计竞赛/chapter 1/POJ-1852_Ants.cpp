#include <stdio.h>
#include <iostream>
using namespace std;

const int MAX_N = 100;
int L, n;

int solve(int *a){
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
    int num_cases;
    scanf("%d", &num_cases);
    for (int j = 0; j < num_cases; j++){
        scanf("%d %d", &L, &n);
        int a[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        solve(a);
    }
}