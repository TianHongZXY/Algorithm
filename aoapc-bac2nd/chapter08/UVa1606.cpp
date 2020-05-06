#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
const int maxn = 5000 + 10;

// struct dot{
//     int x, y, r;
// };
// dot acms[maxn];
// set<pair<int, pair<int, int> > > cofvis;
// int main(){
//     // 复杂度O(n^3) 超时
//     int n;
//     while(scanf("%d", &n) == 1 && n){
//         for(int i = 0; i < n; i++) scanf("%d%d%d", &acms[i].x, &acms[i].y, &acms[i].r);
//         int ans = -1;
//         for(int i = 0; i < n; i++){
//             dot p1 = acms[i];
//             for(int j = i + 1; j < n; j++){
//                 dot p2 = acms[j];
//                 int cofx = p2.y - p1.y, cofy = p1.x - p2.x, cofz = p2.x * p1.y - p1.x * p2.y; // p1 p2确定的直线方程系数
//                 pair<int, pair<int, int> > cofpair = make_pair(cofx, make_pair(cofy, cofz));
//                 if(!cofvis.count(cofpair)) cofvis.insert(cofpair); else continue;
//                 int left[2] = {0}, right[2] = {0}, curmax = -1, onicpc = 0;
//                 for(int k = 0; k < n; k++){ // 对当前的直线划分，遍历所有的点，有三种情况，在icpc上和在其不同侧
//                     dot p3 = acms[k];
//                     if(cofx * p3.x + cofy * p3.y + cofz == 0) onicpc++;
//                     else if(cofx * p3.x + cofy * p3.y + cofz > 0) right[p3.r]++;
//                     else left[p3.r]++;
//                     curmax = max(left[0]+right[1], left[1] + right[0]);
//                 }
//                 curmax += onicpc;
//                 ans = max(curmax, ans);
//             }
//         }
//         printf("%d\n", ans);
//     }

//     return 0;
// }

#include <cmath>
struct Point{
    int x, y, color;
    double theta;
    bool operator < (const Point &rhs) const {
        return theta < rhs.theta;
    }
}p[maxn], pt[maxn];

bool left(const Point &a, const Point &b){
    // 从a逆时针转到b的夹角是否小于180°
    return a.x * b.y - a.y * b.x >= 0;
}

int main(){
    int n;
    while(scanf("%d", &n) == 1 && n){
        for(int i = 0; i < n; i++)
            scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].color);
        int ans = -1;
        for(int i = 0; i < n; i++){ // 枚举点
            int k = 0;
            for(int j = 0; j < n; j++){
                if(j == i) continue;
                pt[k].x = p[j].x - p[i].x;
                pt[k].y = p[j].y - p[i].y;
                if(p[j].color) { pt[k].x = -pt[k].x; pt[k].y = -pt[k].y; }
                pt[k].theta = atan2(pt[k].y, pt[k].x);
                k++;
            }
            sort(pt, pt+k);
            int L = 0, R = 0, cnt = 2;
            while(L < k){
                if(L == R) { R = (R + 1) % k; cnt++; }
                while(L != R && left(pt[L], pt[R])) { R = (R + 1) % k; cnt++; }
                cnt--;
                ans = max(cnt, ans);
                L++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}


// #include<bits/stdc++.h>
// using namespace std;
// const int maxn=1005;
// struct Point{
//     int x, y, color;
//     double theta; // 相对于基准点的极角；acrtan计算
// }p[maxn], pt[maxn]; // p:原数据；pt:变换后的坐标
// int n;
// bool isLeft(const Point& a, const Point& b) { // O-a为分隔线，判断b是否在O-a上侧
//     return a.x * b.y - a.y * b.x >= 0; // 直线方程判断  令z分量为0的向量叉乘，求从a逆时针转向b的夹角sin正负
// }
// int solve() {
//     if (n <= 3) return n; // 1/2/3直接返回
//     int ans=0;
//     for (int i=0; i < n; i ++) { // 枚举n个基准点
//         int k=0;
//         for (int j=0; j < n; j ++) { // 相对坐标变换（将i作为j的原点）
//             if ( i == j) continue; // 同一个点跳过
//             pt[k].x = p[j].x - p[i].x; // 求点j相对于基准点i的坐标 
//             pt[k].y = p[j].y - p[i].y;
//             if (p[j].color == 1) {pt[k].x = -pt[k].x; pt[k].y = -pt[k].y;} // 将黑色点对称变换，到时候只需扫描180即可
//             pt[k].theta = atan2(pt[k].y, pt[k].x); // 利用反正切求角度
//             k ++;
//         }
//         sort(pt, pt+k, [](Point& a, Point& b) {return a.theta < b.theta;}); // 按照极角升序排列
//         int cnt=2, pcur=0, prot=0; // pcur:当前分隔线，prot：旋转线
//         while (pcur < n-1) { // 所有分隔线
//             if (pcur == prot) {prot = (prot+1)%(n-1); cnt ++;} // 后面扣除
//             while (pcur != prot && isLeft(pt[pcur],pt[prot])) {prot = (prot+1)%(n-1); cnt ++;} // 只计数一侧，因为之前黑色点变换过
//             cnt --; // 前面多加一次
//             ans = max(ans, cnt);
//             pcur ++; // 下一个分隔线
//         }
//     }
//     return ans;
// }
// int main() {
//     while (scanf("%d", &n) == 1 && n != 0) {
//         for (int i=0; i < n; i ++) scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].color);
//         printf("%d\n", solve());
//     }
//     return 0;
// }