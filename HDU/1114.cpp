#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
#define min(x, y) (x < y ? x : y)
const int maxn = 500 + 5;
const int maxw = 1e4 + 5;
int E, F, T, N;
int P[maxn], W[maxn], r[maxn], f[maxw];

int cmp(const int i, const int j){
    if(P[i] == P[j]) return W[i] < W[j];
    if(W[i] == W[j]) return P[i] > P[j];
    return 1.0 * P[i] / W[i] > 1.0 * P[j] / W[j];
}

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &E, &F);
        scanf("%d", &N);
        int tgt = F - E;
        for(int i = 1; i <= N; i++){
            scanf("%d%d", &P[i], &W[i]);
            r[i] = i;
        }
        std::sort(r + 1, r + N + 1, cmp);
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        for(int i = 1; i <= N; i++)
            for(int j = W[r[i]]; j <= tgt; j++)
                f[j] = min(f[j], f[j - W[r[i]]] + P[r[i]]);
        if(f[tgt] == INF) printf("This is impossible.\n");
        else printf("The minimum amount of money in the piggy-bank is %d.\n", f[tgt]);
    }

    return 0;
}