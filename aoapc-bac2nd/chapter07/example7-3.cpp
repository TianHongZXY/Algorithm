#include <cstdio>
int X[5000], Y[5000];
int main(){
    int k;
    while(scanf("%d", &k)==1 && k){
        int cnt = 0;
        for(int y = k + 1; y <= 2*k; y++){
            if ((k*y)%(y-k) == 0){
                X[cnt] = (k*y)/(y-k); Y[cnt++] = y;
            }
        }
        printf("%d\n", cnt);
        for(int i = 0; i < cnt; i++)
            printf("1/%d = 1/%d + 1/%d\n", k, X[i], Y[i]);
    }
    return 0;
}