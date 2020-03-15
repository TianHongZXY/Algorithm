//
// Created by TianHongZXY on 2020/3/15.
//
#include <stdio.h>
#define maxn 1010
#define min(a,b) ((a)<(b)?(a):(b))

int main(){
    int n, a[maxn], b[maxn];
    int kase = 0;
    while(scanf("%d", &n) == 1 && n){
        printf("Game %d:\n", ++kase);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        for(;;){
            int A = 0, B = 0;
            for(int i = 0; i < n; i++) {
                scanf("%d", &b[i]);
                if(a[i] == b[i]) A++;
            }
            if(b[0] == 0) break;
            for (int d = 1; d <= 9; d++){
                int c1 = 0, c2 = 0;
                for(int i = 0; i < n; i++){
                    if(a[i] == d) c1++;
                    if(b[i] == d) c2++;
                }
                B += min(c1, c2);
            }
            B -= A;
            printf("    (%d,%d)\n", A, B);
        }
    }
    return 0;
}
