//
// Created by TianHongZXY on 2020/3/13.
//

#include <stdio.h>

int main(){
    int a, b, c;
    int kase = 0;
    while(scanf("%d%d%d", &a, &b, &c) >= 1){
        int found = 0;
        for (int i = 10; i <= 100; i++){
            if(i % 3 == a && i % 5 == b && i % 7 == c){
                kase++;
                printf("Case %d: %d\n",kase, i);
                found = 1;
                break;
            }
        }
        if (!found){
            kase++;
            printf("Case %d: No answer\n", kase);
        }
    }
    return 0;
}