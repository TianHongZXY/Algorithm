//
// Created by TianHongZXY on 2020/3/12.
//

#define LOCAL
#define INF 1000000000
#include <stdio.h>
#include <math.h>
#include <time.h>
void example2_2(){
    int n2, count = 0;
    scanf("%d", &n2);
    long long n = n2;
    while(n > 1){
        if (n % 2 == 1) n = 3 * n + 1;
        else n /= 2;
        count++;
    }
    printf("%d\n", count);
}

void example2_3(){
    double sum = 0;
    for (int i = 0; ;i++){
        double term = 1.0 / (2 * i + 1);
        if (i % 2 == 0) sum += term;
        else sum -= term;
        if (term < 1e-6) break;
    }
    printf("%.6f\n", sum);
}

void example2_4(){
    const int MOD = 1000000;
    int n, S = 0;
    scanf("%d", &n);
    // 25!末尾有6个0，所以25! % MOD = 0，之后大于25的 n! % MOD 都是0了
    if (n >= 25) n = 25;
    int facorial = 1;
    for (int i = 1; i <= n; i++){
        facorial = (facorial * i) % MOD;
        printf("factorial = %d\n", facorial);
//        for (int j = 1; j <= i; j++)
//            facorial = (facorial * j) % MOD;
        S = (S + facorial) % MOD;
    }
    printf("%d\n", S);
    printf("Time used = %.2f\n", (double)clock() / CLOCKS_PER_SEC);
}

void example2_5(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int x, n = 0, min = INF, max = -INF, s = 0;
    while(scanf("%d", &x) == 1){
        s += x;
        n++;
        if (x < min) min = x;
        if (x > max) max = x;
    }
    printf("%d %d %.3f\n", min, max, (double)s/n);
}

void example2_5_fopen(){
    FILE *fin, *fout;
    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");
    int x, n = 0, min = INF, max = -INF, s = 0;
    while(fscanf(fin, "%d", &x) == 1){
        s += x;
        n++;
        if (x < min) min = x;
        if (x > max) max = x;
    }
    fprintf(fout, "%d %d %.3f\n", min, max, (double)s/n);
    fclose(fin);
    fclose(fout);
}

void example2_6(){
    int n = 0, kase = 0;
    while(scanf("%d", &n) == 1 && n){
        int s = 0, min = INF, max = -INF, x;
        for (int i = 0; i < n; i++){
            scanf("%d", &x);
            s += x;
            if (x < min) min = x;
            if (x > max) max = x;
        }
        if (kase) printf("\n");
        printf("Case %d: %d %d %.3f\n", ++kase, min, max, (double)s / n);
    }
}

int main(){
    for (int a = 1; a <= 9; a++)
        for (int b = 0; b <= 9; b++){
            int n = 1100 * a + 11 * b;
            int m = floor(sqrt(n) + 0.5);
            if (m * m == n) printf("%d\n",n);
        }
//    printf("Input for example2_2\n");
//    example2_2();
//    example2_3();
//    printf("Input for example2_4\n");
//    example2_4();
    printf("Input for example2_5\n");
    example2_5();
//    example2_5_fopen();
    return 0;
}