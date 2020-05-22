#include <cstdio>
int main(){
    int n;
    while(scanf("%d", &n) == 1){
        int ans = 1, t;
        for(int i = 0; i < n; i++){
            scanf("%d", &t);
            if(t % 2 == 1)
                ans *= t;
        }
        printf("%d\n", ans);
    }

    return 0;
}