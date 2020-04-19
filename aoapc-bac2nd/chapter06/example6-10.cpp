//
// Created by TianHongZXY on 2020/4/10.
//
#include <cstdio>
#include <cstring>
const int maxn = 10000;
int sum[maxn];

void build(int pos){
    int v;
    scanf("%d", &v);
    if (v == -1) return;
    sum[pos] += v;
    build(pos - 1);
    build(pos + 1);
}

bool init(){
    int v; scanf("%d", &v);
    if (v == -1) return false;
    memset(sum, 0, sizeof(sum));
    int pos = maxn / 2;
    sum[pos] += v;
    build(pos-1); build(pos+1);
    return true;
}

int main(){
    int kase = 0;
    while(init()){
        int begin;
        for(begin = 0; begin < maxn; begin++){
            if(sum[begin] != 0) break;
        }
        printf("Case %d:\n", ++kase);
        bool first = true;
        while(sum[begin]!=0){
            if(first) {printf("%d", sum[begin]); first = !first;}
            else printf(" %d", sum[begin]);
            begin++;
        }
        printf("\n\n");
    }

    return 0;
}