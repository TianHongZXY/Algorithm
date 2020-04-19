//
// Created by TianHongZXY on 2020/3/11.
//
#include <stdio.h>
#include <math.h>

int main(){
    double a = 11111111111.0 * 11111111111.0;
    printf("%f\n", a);

    printf("%f\n", sqrt(-10));
    printf("%f\n", 1.0/0.0);
    printf("%f\n", 0.0/0.0);

    int b, c;
//    scanf("%d%d", &b, &c);
//    printf("%d %d\n", b, c);
//    printf("%%d\\n");
    double pi = acos(-1.0);
    printf("%f\n", sin(30 / 180.0 * pi));
    double f;
    scanf("%lf", &f);
    printf("f = %f\n", f);
    printf("f = %lf\n", f);
    double e; // double 必须用%lf输入
    scanf("%f", &e);
    printf("e = %f\n", e);
    printf("e = %lf\n", e);
    float g;
    scanf("%f", &g);
    printf("g = %f\n", g);
    printf("g = %lf\n", g);
    float h; // float 必须用%f输入
    scanf("%lf", &h);
    printf("h = %f\n", h);
    printf("h = %lf\n", h);

    float t1 = 0.1234567; // float 只能精确掉小数点后六位
    printf("t1 = %f\n", t1);
    double t2 = 0.123456789;
    printf("t2 = %.100lf\n", t2);



    return 0;
}

