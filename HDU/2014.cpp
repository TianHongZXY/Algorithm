#include <cstdio>
#define INF (1<<30)
int main(){
    int n;
    while(scanf("%d", &n) == 1){
        int score, max = -INF, min = INF;
        double final_score = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &score);
            if(score > max) max = score;
            if(score < min) min = score;
            final_score += score;
        }
        final_score = (final_score - max - min) / (n - 2);
        printf("%.2lf\n", final_score);
    }

    return 0;
}