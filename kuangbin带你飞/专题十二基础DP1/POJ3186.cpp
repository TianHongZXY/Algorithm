#include <cstdio>
#define max(x, y) (x > y ? x : y)
const int maxn = 2000 + 5;
int treat[maxn];
int dp[maxn][maxn]; // dp[i][j] 代表已经选i~j情况下，value总和最大值
int main(){
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        scanf("%d", &treat[i]);
    // 反向区间dp
    for(int i = N; i >= 1; i--){
        for(int j = i; j <= N; j++){ // j必须大于等于i
            if(j == i){
                dp[i][j] = N * treat[i]; // 如果i == j，等于选的是最后一个，age = N
            }
            else{
                // dp[i][j]来源于上一状态： dp[i+1][j]和dp[i][j-1]，分别选treat[i] 和 treat[j] 到达，
                // 上一状态在选的时候已经选了(j - i - 1 + 1) = (j - i)个元素，这(j - i)个其实是倒数的(j - i)个元素
                // 所以选的时候是选的第 N - (j - i)个元素，所以 age = N - (j - i)
                dp[i][j] = max(dp[i + 1][j] + treat[i] * (N - (j - i)), dp[i][j - 1] + treat[j] * (N - (j - i)));
            }
        }
    }
    printf("%d\n", dp[1][N]);
    // for(int i = 1; i <= N; i++)
        // for(int j = i; j <= N; j++){
            // printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
        // }
    return 0;
}