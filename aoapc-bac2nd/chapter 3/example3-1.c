//
// Created by TianHongZXY on 2020/3/14.
//
#include <stdio.h>

int main(){
    int c, q = 1;
    while ((c = getchar()) != EOF){
        if (c == '"'){
            printf("%s", q?"``":"''");
            q = !q;
        }
        else printf("%c", c);
    }
    printf("123");
    return 0;
}