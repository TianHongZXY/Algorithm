#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define max(x, y) (x > y ? x : y)
const int maxn = 1e3 + 5;
char arr[maxn][maxn];
int dp[maxn][maxn];

int main(){
    int n;
    while(scanf("%d", &n) == 1 && n){
        for(int i = 0; i < n; i++){
            getchar();
            // scanf("%s", arr[i]);
            for(int j = 0; j < n; j++){
                scanf("%c", &arr[i][j]);
            }
        }
                // cin >> arr[i][j];
        int ans = 1;
        for(int i = 0; i < n; i++){ // 从矩阵右上角开始往下往左搜索，dp[i][j]代表以坐标(i, j)为对角线左下点的最大对称子矩阵的维度
            for(int j = n - 1; j >= 0; j--){
                dp[i][j] = 1; // 每个单独元素是一个维度为1的对称阵
                if(i == 0 || j == n - 1) continue;
                int t = dp[i - 1][j + 1]; // (i, j)的右上角是一个维度为t的对称阵
                for(int k = 1; k <= t; k++){
                    if(arr[i - k][j] == arr[i][j + k])
                        dp[i][j]++;
                    else
                        break;
                }
                ans = max(dp[i][j], ans);
            }
        }
        printf("%d\n", ans);
        // memset(dp, 0, sizeof(dp));
        // memset(arr, 0, sizeof(arr));
    }

    return 0;
}