//
// Created by TianHongZXY on 2020/3/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}
int main(){
    int cnt1[26] = {0}, cnt2[26] = {0};

    char str1[100];
    char str2[100];

    scanf("%s",str1);
    scanf("%s",str2);

    for(int i = 0;i < strlen(str1);i++)
        cnt1[str1[i] - 'A']++;
    for(int i = 0;i < strlen(str2);i++)
        cnt2[str2[i] - 'A']++;
    qsort(cnt1, 26, sizeof(int), cmp);
    qsort(cnt2, 26, sizeof(int), cmp);
    for(int i = 0; i < 26; i++){
        if(cnt1[i] != cnt2[i]) { printf("No"); return 0;}
    }
    printf("Yes");
    return 0;
}
