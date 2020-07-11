#include <cstdio>
#define max(x, y) (x > y ? x : y)
const int maxn = 1e5 + 10;
const int maxw = 4 * 10e4 + 10;
int v[maxn], w[maxn], m[maxn], f[maxw];
int n, W;
int main(){
    scanf("%d%d", &n, &W);
    for(int i = 1; i <= n; i++)
        scanf("%d%d%d", &v[i], &w[i], &m[i]);
    for(int i = 1; i <= n; i++){
        int num = m[i];
        for(int k = 1; num > 0; k = k << 1){
            if(k > num) k = num;
            num -= k;
            for(int j = W; j >= k * w[i]; j--)
                f[j] = max(f[j], f[j - k * w[i]] + k * v[i]);
        }
    }
    printf("%d", f[W]);
    return 0;
}