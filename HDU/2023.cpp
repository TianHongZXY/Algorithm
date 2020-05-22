#include <cstdio>
#include <cstring>
const int maxn = 50 + 10;
double stu_avg[maxn], sub_avg[maxn];
int score[maxn][maxn];
int main(){
    int n, m, s;
    while(scanf("%d%d", &n, &m) == 2){
        memset(stu_avg, 0, sizeof(stu_avg));
        memset(sub_avg, 0, sizeof(sub_avg));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                scanf("%d", &score[i][j]);
                sub_avg[j] += score[i][j];
                stu_avg[i] += score[i][j];
            }
        }
        for(int i = 0; i < n; i++)
            stu_avg[i] /= m;
        for(int i = 0; i < m; i++)
            sub_avg[i] /= n;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int above = 1;
            for(int j = 0; j < m; j++){
                if(score[i][j] < sub_avg[j]) { above = 0; break; }
            }
            if(above) cnt++;
        }
        for(int i = 0; i < n; i++)
            printf("%.2lf%c", stu_avg[i], i == n - 1 ? '\n' : ' ');
        for(int i = 0; i < m; i++)
            printf("%.2lf%c", sub_avg[i], i == m - 1 ? '\n' : ' ');
        printf("%d\n\n", cnt);

    }

    return 0;
}