//
// Created by TianHongZXY on 2020/3/31.
//
#include <bits/stdc++.h>
using namespace std;
int line[15 + 10];
const int maxloop = 1000;

bool iszero(int n){
    bool is0 = false;
    for(int i = 0; i < maxloop; i++){
        int numof0 = 0;
        int first = line[0];
        for(int j = 0; j < n - 1; j++){
            line[j] = abs(line[j] - line[(j+1)]);
            if (line[j] == 0) numof0++;
        }
        line[n - 1] = abs(line[n - 1] - first);
        if (line[n - 1] == 0) numof0++;
        if (numof0 == n) return true;
    }
    return is0;
}

int main(){
    int t;
    scanf("%d", &t);
    int n;
    for(int i = 0; i < t; i++){
        scanf("%d", &n);
        for(int j = 0; j < n; j++)
            scanf("%d", &line[j]);
        if(iszero(n)){ printf("ZERO\n"); }
        else printf("LOOP\n");
    }

    return 0;
}
