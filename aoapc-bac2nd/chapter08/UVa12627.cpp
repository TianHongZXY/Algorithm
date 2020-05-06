#include <cstdio>
#include <cmath>
long long solve(int k, int i){
    if(i <= 0) return 0;
    if(k == 0) return 1;
    if(i >= pow(2, k-1)) return solve(k - 1, i - pow(2, k-1)) + 2 * pow(3, k - 1);
    else return 2 * solve(k - 1, i);
}

int main(){
    int T, k, a, b, kase = 0;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d", &k, &a, &b);
        printf("Case %d: %lld\n", ++kase, solve(k, b) - solve(k, a - 1));
    }
    return 0;
}