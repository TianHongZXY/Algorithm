//
// Created by TianHongZXY on 2020/4/15.
//
#include <bits/stdc++.h>
using namespace std;

int xx, yy;
const int maxn = 100 + 10;
struct dot{
    int x, y;
    double dist;
    dot(){};
    dot(int x, int y): x(x), y(y), dist(pow(x-xx, 2.0) + pow(y-yy, 2.0)){};
    bool operator < (const dot& b) const{
        return dist < b.dist || (dist == b.dist && x < b.x) || (dist == b.dist && x == b.x && y < b.y);
    }
//    ostream& operator << (ostream& out, const dot& d)
//    {
//        out << "(" << d.x << "," << d.y << ")";
//        return out;
//    }
};

int main(){
    int n;
    dot dots[maxn];
    cin >> xx >> yy >> n;
    int x, y;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        dots[i] = dot(x, y);
    }
    sort(dots, dots+n);
    bool first = true;
    for(int i = 0; i < n; i++){
        if (first) {first = false;}
        else {cout << " ";}
        cout << "(" << dots[i].x << "," << dots[i].y << ")";
    }
}
