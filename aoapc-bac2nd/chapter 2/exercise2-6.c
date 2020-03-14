//
// Created by TianHongZXY on 2020/3/13.
//
#include <stdio.h>
#include<unistd.h>
void addition_2(){
    double i;
//  0.1累加100次并不等于10，如果不break这将是个死循环
    for (i = 0; i != 10; i += 0.1) {
        printf("%.1f\n", i);
        if (i > 11) break;
    }
}

int main(){
    int a, b, c, d, e, f, g, h, m;
//  最小的数是123，最大的数是987，因此i = 123 ~ 987/3 = 123 ~ 329
    for (int i = 123; i <= 329; i++){
        int j = i * 2;
        int k = i * 3;
        a = i / 100;
        b = i / 10 % 10;
        c = i % 10;
        d = j / 100;
        e = j / 10 % 10;
        f = j % 10;
        g = k / 100;
        h = k / 10 % 10;
        m = k % 10;
        if (a+b+c+d+e+f+g+h+m == 45 && a*b*c*d*e*f*g*h*m == 362880)
            printf("%d %d %d\n", i, j, k);
    }
    addition_2();
    return 0;
}