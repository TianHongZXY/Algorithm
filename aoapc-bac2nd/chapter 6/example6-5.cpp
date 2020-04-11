//
// Created by TianHongZXY on 2020/4/9.
//
#include <cstdio>
#include <iostream>

const int maxn = 100000 + 10;
int left[10];
int right[10];

void link(int L, int R){
    right[L] = R;
    left[R] = L;
}

int main(){

    int n, m, kase = 0;
    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 1; i <= n; i++){
            left[i] = i - 1;
            right[i] = (i + 1) % (n + 1);
        }
        right[0] = 1;
        left[0] = n;
        int op, x, y, inv = 0;
        while(m--){
            scanf("%d", &op);
            if(op == 4) inv = !inv;
            else{
                scanf("%d%d", &x,&y);
                if(op == 3 && right[y] == x) std::swap(x, y);
                if(op != 3 && inv) op = 3 - op;
                if(op == 1 && x == left[y]) continue;
                if(op == 2 && x == right[y]) continue;

                int lx = left[x], rx = right[x], ly = left[y], ry = right[y];
                if(op == 1){
                    link(lx, rx); link(ly, x); link(x, y);
                }
                else if(op == 2){
                    link(lx, rx); link(x, ry); link(y, x);
                }
                else if(op == 3){
                    if(right[x] == y){ link(lx, y);link(y, x); link(x, ry);}
                    else{ link(lx, y); link(y, rx); link(ly, x); link(x, ry);}
                }
            }
        }

        int b = 0;
        long long ans = 0;
        // 在left和right里把0也算了进去，形成一个环，在right中，right[0]始终指向第一个元素，right[n] = 0，指向第一个元素
        // 所有元素和就是 right[0]~right[n-1]
        for(int i = 0; i <= n; i++){
            b = right[b];
            if(i % 2 == 0) ans += b;
        }
        if(inv && n % 2 == 0) ans = (long long) n * (n + 1) / 2 - ans;
        printf("Case %d: %lld\n", ++kase, ans);
    }
    return 0;
}