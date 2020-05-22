#include <cstdio>
int abs(int a){
    return (a >= 0 ? a : -a);
}

int main(){
    int m, n, score;
    while(scanf("%d%d", &m, &n) == 2){
        int min = -(1 << 31), row = 1, col = 1;
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++){
                scanf("%d", &score);
                if(abs(min) < abs(score)){
                    min = score;
                    row = i; col = j;
                }
            }
        printf("%d %d %d\n", row, col, min);
    }

    return 0;
}