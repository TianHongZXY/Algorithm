#include <cstdio>
#define min(x, y)  (x > y ? y : x)

int main(){
    int T, N, K, S, t1, t2;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
        scanf("%d%d%d", &N, &K, &S);
        t1 = t2 = K - 1;
        t1 += N + 1;
        t2 += K - S + N - S + 1;

        printf("Case #%d: %d\n", i, min(t1, t2));
    }
    
    return 0;
}