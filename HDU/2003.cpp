#include <cstdio>

int main(){
    double n;
    while(scanf("%lf", &n) == 1){
        printf("%.2lf\n", n > 0 ? n : -n);
    }
    
    return 0;
}