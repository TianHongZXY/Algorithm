//
// Created by TianHongZXY on 2020/4/1.
//
#include <bits/stdc++.h>
using namespace std;
struct dot{
    int x, y;
    bool operator < (const dot& d) const{
        return x < d.x || (x == d.x && y < d.y);
    }
    bool operator == (const dot& d) const{
        return (x == d.x && y == d.y);
    }
    dot(int a, int b){this->x = a; this->y = b;}
    dot(){this->x = 0; this->y = 0;}
};

int main(){
    // 10ms
    int t, n;
    dot q;
    scanf("%d", &t);
    while(t--){
        vector<dot> a;
        set<dot> b;
        scanf("%d", &n);
        double mi = 0;
        for(int i = 0; i < n; i++){
            scanf("%d%d", &q.x, &q.y);
            mi += q.x;
            a.push_back(q);
            b.insert(q);
        }
        mi = mi * 2 / n;
        sort(a.begin(), a.end());
        int mid;
        if (a.size() % 2 == 0){
            mid = a[a.size()/2].x + a[a.size()/2 - 1].x;
//            mid /= 2;
        }
        else{
            mid = a[a.size()/2].x * 2;
        }
        if (mi != mid) {printf("NO\n"); continue;}
        bool sym = true;
        for(int i = 0; i < a.size() / 2; i++){
            if (b.count(dot(mid - a[i].x, a[i].y)))
                continue;
            else{
                sym = false;
                break;
            }
        }
        if(sym) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}

