#include <cstdio>
int money[] = {100, 50, 10, 5, 2, 1};

int solve(int x){
    int num = 0;
    for(int i = 0; x != 0 && i < 6; i++){
        num += (x / money[i]);
        x = (x % money[i]);
    }
    return num;
}

int main(){
    int n;
    while(scanf("%d", &n) == 1 && n){
        int ans = 0, x;
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            ans += solve(x);
        }
        printf("%d\n", ans);
    }

    return 0;
}