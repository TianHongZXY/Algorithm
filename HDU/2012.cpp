#include <cstdio>
#include <cmath>
int res(int n){
    return n*n + n + 41;
}

bool is_prim(int x){
    if(x == 1) return false; // 1不是质数
    double upbound = sqrt(x);
    for(int i = 2; i <= upbound; i++){
        if(x % i == 0) return false;
    }
    return true;
}
int main(){
    int x, y;
    while(scanf("%d%d", &x, &y) == 2 && (x||y)){
        bool ok = true;
        for(int i = x; i <= y; i++){
            if(!is_prim(res(i))){
                printf("Sorry\n");
                ok = false; break;
            }
        }
        if(ok) printf("OK\n");
    }

    return 0;
}