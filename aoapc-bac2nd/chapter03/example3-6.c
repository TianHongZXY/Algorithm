//
// Created by TianHongZXY on 2020/3/15.
//
#include <stdio.h>
#include <string.h>
#define maxn 105

int less(const char* s, int p, int q){
    int n = strlen(s);
    for (int i = 0; i < n; i++){
        if (s[(i + p) % n] != s[(i + q) % n])
            return s[(i + p) % n] < s[(i + q) % n];
    }
    return 0;
}

int main(){
    int T;
    char s[maxn];
    scanf("%d", &T);

    while(T--){
        int min_start = 0;
        scanf("%s", s);
        int n = strlen(s);
        int p = 0, q = 0;
        while(p < n && q < n){
            if (less(s, p, q)){q++;min_start=p;}
            else{p++;min_start=q;}
        }
        for(int i = 0; i < n; i++)
            putchar(s[(i+min_start) % n]);
        putchar('\n');
    }
}

