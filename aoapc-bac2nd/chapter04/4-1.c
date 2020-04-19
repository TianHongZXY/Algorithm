//
// Created by TianHongZXY on 2020/3/18.
//
#include <stdio.h>
#include <math.h>

struct Point{ double x, y;};

double dist(struct Point a, struct Point b){
    return hypot(a.x - b.x, a.y - b.y);
}

typedef struct{double x, y;}Point_;
double dist_(Point_ a, Point_ b){
    return hypot(a.x - b.x, a.y - b.y);
}

int main(){
    Point_ p1, p2;
    p1.x = 0; p1.y = 0;
    p2.x = 1; p2.y = 1;
    double d = dist_(p1, p2);
    printf("%f\n", d);


    return 0;
}
