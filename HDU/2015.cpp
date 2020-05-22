#include <cstdio>

int main(){
    int n, m;
    int cache[101];
    for(int i = 1; i <= 100; i++) cache[i] = i * 2;
    while(scanf("%d%d", &n, &m) == 2){
        int cnt = 0, ans = 0, first = 1;
        for(int i = 1; i <= n; i++){
            cnt += 1; ans += cache[i];
            if(i % m == 0){
                if(first) { printf("%d", ans / cnt); first = 0; }
                else printf(" %d", ans / cnt);
                cnt = 0; ans = 0;
            }
        }
        if(n % m == 0) printf("\n");
        else{
            printf(" %d\n", ans / cnt);
        }
    }

    return 0;
}