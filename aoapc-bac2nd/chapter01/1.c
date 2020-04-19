//
// Created by TianHongZXY on 2020/3/11.
//

#include <stdio.h>
#include <math.h>
int main(){
    printf("%d\n", 1 + 2);
    printf("%.1f\n", 8 / 5);
    printf("%.1f\n", 8.0 / 5);
    printf("%d\n", -8 / 5);
    printf("%.1f\n", -8.0 / 5);

    printf("%.8f", 1 + 2 * sqrt(3) / (5 - 0.1));

//    int a, b;
//    scanf("%d%d", &a, &b);
//    printf("%d\n", a + b);

    const double pi = acos(-1.0);
    double r, h, s1, s2, s;
    scanf("%lf%lf", &r, &h);
    s1 = pi * r * r;
    s2 = 2 * pi * r * h;
    s = 2 * s1 + s2;
    printf("Area = %.3f\n", s);

    int n, m;
    scanf("%d", &n);
    m = (n % 10) * 100 + (n / 10 % 10) * 10 + n / 100;
    printf("%03d\n", m);

    // 不使用变量的变量交换
    int c = 10, d = 20;
    c = c + d;
    d = c - d;
    c = c - d;
    printf("%d %d\n", c, d);

    c ^= d ^= c ^= d;
    printf("%d %d\n", c, d);

    return 0;
}
