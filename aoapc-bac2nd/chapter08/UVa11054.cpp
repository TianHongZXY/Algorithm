#include <cstdio>
const int maxn = 100000 + 10;
int a[maxn];
int main(){ // 1390ms，复杂度O(n^2)，直观但不好
    int n;
    while(scanf("%d", &n) == 1 && n){
        long long ans = 0;
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        // 从左往右，以此满足每一个点后才移动到下一点
        for(int i = 0; i < n; i++){
            if(a[i] == 0) continue; // 当前点已被满足
            for(int j = i + 1; j < n; j++){
                if (a[j] == 0) continue; 
                if(a[i] > 0 && a[j] < 0) // ai买酒，aj卖酒
                    if(-a[j] >= a[i]) { a[j] += a[i]; ans += (j - i) * a[i]; break; } // aj供应量大于ai需求量，ai被满足，跳出j循环
                    else { ans += (j - i) * (-a[j]); a[i] += a[j]; a[j] = 0;} // ai需求量大于aj供应量，aj被掏空，继续搜索供应酒的j
                else if (a[i] < 0 && a[j] > 0)
                    if(-a[i] > a[j]) { ans += (j - i) * a[j]; a[i] += a[j]; a[j] = 0;}
                    else { ans += (j - i) * (-a[i]); a[j] += a[i]; break; }
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}

// 归纳法，运到/运出ai的酒必定经过ai+1，所以先把酒运到ai+1，总工作量 + ai，此时ai被满足，ai+1的需求量变成 ai+1与ai之和
#include <algorithm>
int main__(){ // 10ms
    int n;
    while(scanf("%d", &n) == 1 && n){
        long long ans = 0;
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        for(int i = 0; i < n - 1; i++){
            ans += std::abs(a[i]);
            a[i + 1] += a[i];
        }
        printf("%lld\n", ans);
    }
    
    return 0;
}