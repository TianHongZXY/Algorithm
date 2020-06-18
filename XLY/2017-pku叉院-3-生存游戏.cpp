//
// Created by TianHongZXY on 2020/4/15.
//
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10, maxm = 100 + 10;
int matrix[maxn][maxm];
int helper[maxn][maxm];
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            scanf("%d", &matrix[i][j]);
        }
    memcpy(helper, matrix, maxn * maxm);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int cnt = 0;
            for(int dx = -1; dx <= 1; dx++)
                for(int dy = -1; dy <= 1; dy++)
                    if(i + dx >= 0 && i + dx < n && j + dy >= 0 && j + dy < m && (dx != 0 || dy != 0)){
                        if(helper[i+dx][j+dy] == 1) cnt++;
                    }
            if(cnt < 2) matrix[i][j] = 0;
            else if(cnt == 3) matrix[i][j] = 1;
            else if(cnt == 2) continue;
            else if(cnt > 3) matrix[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++) {
        bool first = true;
        for (int j = 0; j < m; j++) {
            if(first) first = false;
            else cout << " ";
            cout << matrix[i][j];
        }
        cout << endl;
    }
    return 0;
}
