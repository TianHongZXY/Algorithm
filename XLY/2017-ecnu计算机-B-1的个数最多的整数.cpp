// https://acm.ecnu.edu.cn/problem/3303/
#include <cstdio>
#include <cmath>
unsigned long long bits[70];
int main(){
    for(int i = 0; i <= 63; i++)
        bits[i] = (unsigned long long)pow(2, i);
    int T, kase = 0;
    unsigned long long a, b;
    scanf("%d", &T);
    while(T--){
        scanf("%llu%llu", &a, &b);
        // printf("%lu %lu\n", a, b);
        unsigned long long ans = a;
        for(int i = 0; i <= 63; i++){
            if(ans & bits[i]) continue;
            else{
                if((ans | bits[i]) <= b) ans |= bits[i];
                else break;
            }
        }
        printf("Case %d: %llu\n", ++kase, ans);
    }
    return 0;
}