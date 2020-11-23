//
// Created by TianHongZXY on 2020/4/4.
//
#include <bits/stdc++.h>
using namespace std;
int t, n, kase;
const int maxn = 1000 + 10;

struct node{
    int s,e,id;
    char res;
}a[maxn];

bool cmp1(node a,node b){
    return a.s < b.s;
}

bool cmp2(node a,node b){
    return a.id < b.id;
}

int main(){
    scanf("%d", &t);
    while(t--){
        bool possible = true;
        string res = "";
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            a[i].id = i;
            scanf("%d%d", &a[i].s, &a[i].e);
        }
        sort(a, a+n, cmp1);
        bool Cbusy, Jbusy;
        int eofc = -1, eofj = -1;
        for(int i = 0; i < n; i++){
            Cbusy = a[i].s >= eofc ? false : true;
            Jbusy = a[i].s >= eofj ? false : true;
            if(Cbusy && Jbusy){
                printf("Case #%d: IMPOSSIBLE\n", ++kase);
                possible = false;
                break;
            }
            else if(!Cbusy){
                eofc = a[i].e;
                a[i].res = 'C';
            }
            else if(!Jbusy){
                eofj = a[i].e;
                a[i].res = 'J';
            }
        }
        if(possible){
            sort(a, a+n, cmp2);
            printf("Case #%d: ", ++kase);
            for(int i = 0; i < n; i++){
                printf("%c", a[i].res);
            }
            printf("\n");
        }
    }

    return 0;
}
