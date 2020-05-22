#include <cstdio>
int main(){
    int t;
    char grade[] = {'A', 'B', 'C', 'D', 'E'};
    while(scanf("%d", &t) == 1){
        if(t < 0 || t > 100) { printf("Score is error!\n"); continue; }
        t /= 10;
        if(t >= 9) printf("%c\n", grade[0]);
        else if(t <= 5) printf("%c\n", grade[4]);
        else printf("%c\n", grade[9-t]);
    }

    return 0;
}
