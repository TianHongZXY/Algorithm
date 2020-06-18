#include <cstdio>
#include <cmath>
bool isprime(int x){
    // 1不是素数
    if(x == 1) return false;
    int xroot = (int)floor(sqrt(x));
    for(int i = 2; i <= xroot; i++){
        if(x % i == 0) return false;
    }
    return true;
}

int main(){
    int X, Y;
    scanf("%d%d", &X, &Y); // X, Y谁大谁小没说，这是个坑！
    int cnt = 0;
    if(X > Y){
        int t = X;
        X = Y;
        Y = t;
    }
    for(int i = X; i <= Y; i++)
        if(isprime(i)){
            cnt++;
            // printf("%d: %d\n", cnt, i);
        }
    printf("%d\n", cnt);

    return 0;
}