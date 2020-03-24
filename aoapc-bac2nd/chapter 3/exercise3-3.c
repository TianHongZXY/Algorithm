//
// Created by TianHongZXY on 2020/3/16.
//
#include <stdio.h>

int main(){
    int T;
    scanf("%d", &T);
//    9996
//    末位0~6 各一次, 前面的数每个次数*6，然后变为9989,
//    首位9 当前要被重复996次，次位9要被重复96次，次位要被重复9次，
    int n;
    while(T--){
        int count[] = {0,0,0,0,0,0,0,0,0,0};
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            int j = i;
            while(j) {
                int last = j % 10;
                count[last]++;
                j /= 10;
            }
        }
        for(int i = 0; i < 9; i++){
            printf("%d ", count[i]);
        }
        printf("%d\n", count[9]);
    }
    return 0;
}
