//
// Created by TianHongZXY on 2020/3/17.
//
#include <stdio.h>
#include <string.h>
#define maxn 85

int main(){
// 还是有错，还是参考dalao用cpp的解法吧
    char s[maxn];
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", s);
        int n = strlen(s);
        int min = maxn;
        char temp1[maxn];
        char temp2[maxn];
        for (int i = 1; i < n / 2 + 1; i++) {
            strncpy(temp1, s, i);
            strncpy(temp2, s + i, i);
            if (strcmp(temp1, temp2) == 0){
                int j;
                for(j = i; j <= n; j++)
                    if (s[j] != s[j%i])
                        break;
                if(j == n && i < min)
                    min = i;
            }
        }
        if (T == 0)
            printf("%d\n", min);
        else
            printf("%d\n\n", min);
    }

    return 0;
}
