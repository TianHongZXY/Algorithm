#include <cstdio>

int main(){
    int m, n;
    while(scanf("%d%d", &m, &n) == 2){
        int L, M, R;
        bool first = true;
        for(int i = m; i <= n; i++){
            L = i / 100; M = (i / 10) % 10; R = i % 10;
            if(L*L*L + M*M*M + R*R*R == i){
                if(first){
                    printf("%d", i);
                    first = false;
                }else printf(" %d", i);
            }
        }
        if(first) printf("no\n"); else printf("\n");
    }
    return 0;
}