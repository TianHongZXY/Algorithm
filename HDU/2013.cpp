#include <cstdio>

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        int ans = 1;
        for(int i = 1; i < n; i++){
            ans = (ans + 1) * 2;
        }
        printf("%d\n", ans);
    }

    return 0;
}