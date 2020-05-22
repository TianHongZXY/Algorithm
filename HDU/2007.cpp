#include <cstdio>

int main(){
    int m, n;
    while(scanf("%d%d", &m, &n) == 2){
        int even_b, even_e, odd_b, odd_e;
        if(m > n){
            int temp = n;
            n = m;
            m = temp;
        }
        if(m % 2 == 0){
            even_b = m;
            odd_b = m + 1;
        }else{
            even_b = m + 1;
            odd_b = m;
        }
        if(n % 2 == 0){
            even_e = n;
            odd_e = n - 1;
        }else{
            even_e = n - 1;
            odd_e = n;
        }
        long long even_sum = 0, odd_sum = 0;
        for(int i = even_b; i <= even_e; i += 2){
            even_sum += (i*i);
        }
        for(int i = odd_b; i <= odd_e; i += 2){
            odd_sum += (i*i*i);
        }
        printf("%lld %lld\n", even_sum, odd_sum);
    }

    return 0;
}