#include <cstdio>
#define max(x, y) (x > y ? x : y)
const int maxn = 100 + 10;
int h[maxn];
int up[maxn], down[maxn];

// 其实就是求正向和反向的最长下降子序列，那么求正向的最长下降和最长上升子序列就可以了
int main(){
    int k, n;
    scanf("%d", &k);
    while(k--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &h[i]);
        int ans = -1;
        for(int i = 0; i < n; i++){
            up[i] = 1; down[i] = 1;
            for(int j = 0; j < i; j++){
                if(h[i] > h[j])
                    up[i] = max(up[i], up[j] + 1);
                else if(h[i] < h[j])
                    down[i] = max(down[i], down[j] + 1);
            }
            ans = max(ans, up[i]);
            ans = max(ans, down[i]);
        }
        printf("%d\n", ans);
    }

    return 0;
}