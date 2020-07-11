#include <cstdio>
#include <cstring>
#include <algorithm>
#define max(x, y) (x > y ? x : y)
int N, M;
const int maxn = 500 + 5;
const int maxm = 5000 + 5;
int P[maxn], Q[maxn], V[maxn], f[maxm], r[maxn];

int cmp(const int i, const int j){
    return Q[i] - P[i] < Q[j] - P[j];
}

int main(){
    while(scanf("%d%d", &N, &M) == 2){
        for(int i = 1; i <= N; i++){
            scanf("%d%d%d", &P[i], &Q[i], &V[i]);
            r[i] = i;
        }
        std::sort(r + 1, r + N + 1, cmp);
        for(int i = 1; i <= N; i++){
            for(int j = M; j >= Q[r[i]]; j--){
                f[j] = max(f[j], f[j - P[r[i]]] + V[r[i]]);
            }
        }
        printf("%d\n", f[M]);
        memset(f, 0, sizeof(f));
    }

    return 0;
}