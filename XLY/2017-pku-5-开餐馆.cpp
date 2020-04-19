//
// Created by TianHongZXY on 2020/4/15.
//
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
int profit[maxn], m[maxn], p[maxn];
int n, k;

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        cin >> n >> k;
        for(int i = 0; i < n; i++){
            cin >> m[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> p[i];
            profit[i] = p[i];
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(m[i] - m[j] > k)
                    profit[i] = max(profit[i], profit[j] + p[i]);
            }
        }
        int maxx = 0;
        for(int i = 0; i < n; i++) maxx = max(maxx, profit[i]);
        cout << maxx << endl;
    }
}
