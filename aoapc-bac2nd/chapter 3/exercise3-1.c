//
// Created by TianHongZXY on 2020/3/16.
//
#include <stdio.h>
#include <string.h>


int main(){
    int T;
    char s[85];
    scanf("%d", &T);
    while(T--){
        int num_o = 0;
        scanf("%s", s);
        int n = strlen(s);
        int score = 0;
        for(int i = 0; i < n; i++){
            if (s[i] == 'O'){
                num_o++;
                score += num_o;
            }
            else num_o = 0;
        }
        printf("%d\n", score);
    }

    return 0;
}
