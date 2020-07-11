// 题目链接 https://blog.csdn.net/weixin_39626452/article/details/95103839
#include <cstdio>
#define max(x, y) (x > y ? x : y)
const int maxn = 1e4;
const int maxm = 1e4;
int f[maxn], d[maxn];

int main(){
    int T, n, m;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= m; i++)
            scanf("%d", &d[i]);
        for(int i = 1; i <= m; i++)
            for(int j = n; j >= d[i]; j--){
                f[j] = max(f[j], f[j - d[i]] + 1);
            }
        printf("%d\n", f[n]);
    }
    return 0;
}