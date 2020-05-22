#include <cstdio>
#include <cstring>
#define PI 3.1415927
int main(){
    double r, volume;
    while(scanf("%lf", &r) == 1){
        volume = 4.0/3 * PI * (r*r*r);
        printf("%.3lf\n", volume);
    }
    
    return 0;
}