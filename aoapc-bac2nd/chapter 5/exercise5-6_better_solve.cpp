//
// Created by TianHongZXY on 2020/4/1.
//
#include <bits/stdc++.h>
using namespace std;

int main(){
    // 20ms 比我的方法简洁易懂 但速度慢了些
    int t, n, x, y;
    scanf("%d", &t);
    while(t--) {
        map<int, vector<int> > y2x;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &x, &y);
            y2x[y].push_back(x);
        }
        set<int> s;
        for(auto row: y2x){
            sort(row.second.begin(), row.second.end());
            int right = (row.second.size() % 2 == 0) ? row.second.size()/2 : row.second.size()/2+1;
            for(int i = 0; i < right; i++) s.insert(row.second[i] + row.second[row.second.size()-1-i]);
        }
        if(s.size() == 1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
