#include <cstdio>

int main(){
    int n;
    double t;
    while(scanf("%d", &n) == 1 && n){
        int a = 0, b = 0, c = 0;
        for(int i = 0; i < n; i++){
            scanf("%lf", &t);
            if(t < 0) a++;
            else if(t == 0) b++;
            else c++;
        }
        printf("%d %d %d\n", a, b, c);
    }

    return 0;
}