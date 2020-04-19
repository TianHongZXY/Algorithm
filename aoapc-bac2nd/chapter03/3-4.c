//
// Created by TianHongZXY on 2020/3/16.
//
#include <stdio.h>
#include <string.h>
#define maxn 10000000 + 10
char s[maxn];

int main(){
    int a = 123;
    printf("%d %o %x\n", a, a, a);
    // << 运算符优先级比 - 低，所以位运算要加括号
    printf("%d %d %d\n", a, (a << 1) - 1, a << 1 - 1);
    printf("%u\n", -1);

    scanf("%s", s);
    int tot = 0;
    int n = strlen(s);
    for(int i = 0; i < n; i++)
        if(s[i] == '1') tot++;
    printf("%d\n", tot);
    return 0;
}