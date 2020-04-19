//
// Created by TianHongZXY on 2020/3/15.
//
#include <stdio.h>
#include <string.h>
#include <time.h>

#define maxn 100005
int ans[maxn];

int main(){
    memset(ans, 0, sizeof(ans));
    int T, n;
    for(int m = 1; m < maxn; m++){
        int x = m, y = m;
        while(x > 0){y += x % 10; x /= 10;}
        if(ans[y] == 0 || m < ans[y]) ans[y] = m;
    }
//    double time = (double)clock() / CLOCKS_PER_SEC;
//    printf("%f\n", time);
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }

    return 0;
}
