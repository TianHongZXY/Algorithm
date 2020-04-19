#include <bits/stdc++.h>
using namespace std;
const int maxn = 30 + 2;
vector<int> sqs;

int main(){
    int m, n, h, cubic, kase = 1;
    while(scanf("%d%d", &m, &n) == 2 && m){
        sqs.clear(); sqs.push_back(0);
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++){
                scanf("%d", &h); sqs.push_back(h);
            }
        scanf("%d", &cubic);
        sort(sqs.begin() + 1, sqs.end());
        int lo = 1, hi = m * n, mid;
        while(lo <= hi){
            int sum = 0;
            mid = lo + (hi - lo) / 2;
            h = sqs[mid];
            for(int i = 1; i < mid; i++)
                sum += (h - sqs[i]);
            if (sum * 100 > cubic) hi = mid - 1;
            else lo = mid + 1;
        }
        // 跳出循环时，1~(lo-1)是要淹没的格子，lo-1可能被淹没也可能和海平面齐平
        for(int i = 1; i <= lo - 1; i++)
            cubic -= (sqs[lo - 1] - sqs[i]) * 100; // 填满前lo-1个，剩余的水给lo - 1个格子平分
        double level = (double) cubic / ((lo - 1) * 100) + sqs[lo - 1];
        double percent;
        if(sqs[lo-1] < level) percent = (double)(lo - 1) / (m * n); // 如果严格被淹没
        else percent = (double)(lo - 2) / (m * n); // 不严格被淹没，格子要-1
        printf("Region %d\n", kase++);
        printf("Water level is %.2lf meters.\n", round(level*100)/100);
        printf("%.2lf percent of the region is under water.\n\n", round(percent*10000)/100);
    }
    return 0;
}