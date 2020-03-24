//
// Created by TianHongZXY on 2020/3/16.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>

double weight(char c){
    double molecular[] = {12.01, 1.008, 16.00, 14.01};
    char mole[] = "CHON";
    for(int j = 0; j < 4; j++)
        if(c == mole[j])
            return molecular[j];
    return 0;
}

int main(){
    int T;
    char s[100];
    scanf("%d", &T);
    while(T--){
        scanf("%s", s);
        int n = strlen(s);
        double mass = 0;
        int ten = 0;
        int one = 0;
        char m = ' ';
        for(int i = 0; i < n; i++) {
            if (isalpha(s[i])) {
                if (!one) mass += weight(m);
                else mass += weight(m) * (10 * ten + one);
                m = s[i];
                ten = 0;
                one = 0;
            } else {
                if (one) {ten = one; one = s[i] - '0';}
                else one = s[i] - '0';
            }
        }
        if(!one) mass += weight(m);
        else mass += weight(m) * (10 * ten + one);

        printf("%.3f\n", mass);
    }

    return 0;
}
