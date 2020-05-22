#include <cstdio>
#include <cmath>
int main(){
    double x1, y1, x2, y2, ans;
    while(scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2) == 4){
        ans = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
        printf("%.2lf\n", ans);
    }
    return 0;
}