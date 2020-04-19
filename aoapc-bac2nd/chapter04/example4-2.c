//
// Created by TianHongZXY on 2020/3/21.
//
#include <stdio.h>
#include <string.h>
#define maxn 100

int left, chance;
char s[maxn], s2[maxn];
int win, lose;

void guess(char ch){
    int lens = strlen(s);
    int bad = 1;
    for(int i = 0; i < lens; i++){
        if (s[i] == ch) {left--; bad = 0; s[i] = ' ';}
    }
    if (bad) chance--;
}

int main(){
    int rnd;
    while(scanf("%d%s%s", &rnd, s, s2) == 3 && rnd != -1){
        printf("Round %d\n", rnd);
        win = lose = 0;
        chance = 7;
        left = strlen(s);
        int lens2 = strlen(s2);
        for(int i = 0; i < lens2; i++){
            guess(s2[i]);
            if (!left) {win = 1; break;}
            if (!chance){lose = 1; break;}
        }
        if (win) printf("You win.\n");
        else if (lose) printf("You lose.\n");
        else printf("You chickened out.\n");
    }

    return 0;
}