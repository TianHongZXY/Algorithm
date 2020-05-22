#include <cstdio>
#include <cmath>

int main(){
    double n;
    int m;
    while(scanf("%lf%d", &n, &m) == 2){
        double ans = 0;
        for(int i = 0; i < m; i++){
            ans += n;
            n = sqrt(n);
        }
        printf("%.2lf\n", ans);
    }

    return 0;
}