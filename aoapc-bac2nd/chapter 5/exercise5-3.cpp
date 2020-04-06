//
// Created by TianHongZXY on 2020/3/31.
//
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    queue<int> q;
    while(scanf("%d", &n) == 1 && n){
        for(int i = 1; i <= n; i++){
            q.push(i);
        }
        printf("Discarded cards:");
        int t;
        while(q.size() > 2){
            t = q.front();
            printf(" %d,", t);
            q.pop();
            t = q.front();
            q.push(t);
            q.pop();
        }
        if (q.size() == 2){
            t = q.front();
            printf(" %d", t);
            q.pop();
        }
        printf("\nRemaining card: %d\n", q.front());
        q.pop();
    }
    return 0;
}
