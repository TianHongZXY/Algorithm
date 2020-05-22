#include <cstdio>
#define INF (1 << 30)
int main(){
    int n, m, t;
    while(scanf("%d%d", &n, &m) == 2 && (n || m)){
        int first = 1;
        for(int i = 0; i < n; i++){
            scanf("%d", &t);
            if(m <= t){
                if(first) { printf("%d %d", m, t); first = 0; } else printf(" %d %d", m, t);
                m = INF;
            }
            else{
                if(first) { printf("%d", t); first = 0; } else printf(" %d", t);
            }
        }
        printf("\n");
    }
    return 0;
}