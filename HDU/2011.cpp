#include <cstdio>
const int maxn  = 1000 + 10;
double result[maxn];

int main(){
    int m;
    scanf("%d", &m);
    int cof = 1;
    for(int j = 1; j <= 1000; j++){
        result[j] = result[j - 1] + cof * (1.0 / j);
        cof *= -1;
    }
    for(int i = 0; i < m; i++){
        int n; scanf("%d", &n);
        printf("%.2lf\n", result[n]);
    }

    return 0;
}