//
// Created by TianHongZXY on 2020/4/4.
//
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
int trace, t, n, kase, numr, numc;
int M[maxn][maxn];
map<int, set<int> > rows;
map<int, set<int> > cols;
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                scanf("%d", &M[i][j]);
                if(i==j) trace += M[i][j];
            }
        for(int i = 0; i < n; i++){
            for (int j = 0; j < n; j++) {
                if (!rows[i].count(M[i][j])) rows[i].insert(M[i][j]);
                else {numr++; break;}
            }
        }
        for(int i = 0; i < n; i++){
            for (int j = 0; j < n; j++) {
                if (!cols[i].count(M[j][i])) cols[i].insert(M[j][i]);
                else {numc++; break;}
            }
        }
        printf("Case #%d: %d %d %d\n",++kase, trace, numr, numc);
        rows.clear(); cols.clear();
        numr = 0; numc = 0; trace = 0;
    }
    return 0;
}