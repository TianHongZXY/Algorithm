#include <cstdio>
#include <cstring>
const int INF_NUM = 0x3f3f3f3f;
const int MAXN = 100;
int dp[MAXN][MAXN]; // dp[i][j]等于Ai~Aj的链乘最小值
int p[MAXN]; // 矩阵Ai的维度为p[i-1],p[i]

// 递归法
int search(int i, int j){
	// 记忆化
	if(dp[i][j] < INF_NUM) return dp[i][j];
	// 初始化条件
	if(i == j) dp[i][j] = 0;
	else{
		// 循环一遍，找到最小的
		for(int k = i; k < j; ++ k){
            // 转移方程 dp[i][j] = dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j]
			int ans = search(i, k) + search(k+1, j) + p[i-1]*p[k]*p[j];
			if(ans < dp[i][j]) dp[i][j] = ans;
		}
	}
	return dp[i][j];
}

// 递推法
int matrix_chain(int n){
	// 初始化，长度为 1 的情况都是0
    memset(dp, 0, sizeof(dp));
	// 从长度为 2 开始循环
	for(int len = 2; len <= n; ++ len){
		for(int i = 1; i <= n - len + 1; ++ i){
			int j = i + len - 1;
			for(int k = i; k < j; ++ k){
				int ans = dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j];
				if(dp[i][j] > ans) dp[i][j] = ans;
            }
		}
	}
	return dp[1][n];
}

int main(){
    int n; // n为矩阵的个数
	memset(dp, 0x3f, sizeof(dp));
	int ans = search(1, n);
    return 0;
}