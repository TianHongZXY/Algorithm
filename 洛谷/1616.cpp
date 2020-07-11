#include <cstdio>
#define max(x, y) (x > y ? x : y)
const int maxn = 1e4 + 10;
const int maxt = 1e7 + 10;
int w[maxn], v[maxn], f[maxt];
int t, m;

int main(){
    scanf("%d%d", &t, &m);
    for(int i = 1; i <= m; i++)
        scanf("%d%d", &w[i], &v[i]);
    for(int i = 1; i <= m; i++)
        for(int j = w[i]; j <= t; j++)
            f[j] = max(f[j], f[j - w[i]] + v[i]);
    printf("%d", f[t]);
    return 0;
}