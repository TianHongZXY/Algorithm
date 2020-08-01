#include <cstdio>
#include <cstring>
#include <cmath>

int main(){
    int T, x, y;
    double res;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &x, &y);
        res = pow(x, y);
        while(res >= 10){
            res = floor(res / 10);
        }
        if(res == 1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}