#include <cstdio>
const int maxn = 100 + 10;
const int maxm = 100 + 10;
int M[maxn][maxm];
int K[maxn][maxm];
int n, m, h, w;

int conv(int upx, int upy){
    int res = 0;
    for(int i = upx; i < upx + h; i++)
        for(int j = upy; j < upy + w; j++){
            res += M[i][j] * K[i - upx + 1][j - upy + 1];
        }
    return res;
}

int main(){
    scanf("%d%d",&n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &M[i][j]);
    
    scanf("%d%d",&h, &w);
    for(int i = 1; i <= h; i++)
        for(int j = 1; j <= w; j++)
            scanf("%d", &K[i][j]);

    int res;
    for(int uprow = 1; uprow + h - 1 <= n; uprow++){
        for(int upcol = 1; upcol + w - 1 <= m; upcol++){
            res = conv(uprow, upcol);
            printf("%d%c", res, upcol == m - w + 1 ? '\n' : ' ');
        }
    }

    return 0;
}