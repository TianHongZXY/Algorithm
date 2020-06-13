#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define max(a, b) ((a) > (b) ? a : b)
using namespace std;
const int N = 205, M = 805, base = 400;//代表开始的偏移量
int dp[N][21][805], n, m, p[N], d[N], no[N];
void f() {
	memset(dp, -0x3f, sizeof(dp));
	//初始状态设置为0
	dp[0][0][base] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) { //可以1个人不选 
			for (int k = 0; k < M; k++) {
				dp[i][j][k] = dp[i - 1][j][k]; //不选i这个人 
				int t = k - (p[i] - d[i]);
				if (t < 0 || t >= M) continue;
				if (j < 1) continue; //防止越界 
				dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][t] + p[i] + d[i]); 
			}
		}
	} 
	int v = 0; //找出k值最小的
	while (dp[n][m][base - v] < 0 && dp[n][m][base + v] < 0) v++;
	if (dp[n][m][base - v] > dp[n][m][base + v]) {
		v = base - v; //选择 k值同 但p+d最大的一个		
	} else {
		v = base + v; 
	}
	int psum = 0, dsum = 0;
	int i = n, j = m, cnt = 0;
	while (j) {
		if (dp[i][j][v] == dp[i - 1][j][v]) {
			i--; // 代表没有选i这个人 
		} else {
			no[cnt++] = i;
			psum += p[i];
			dsum += d[i];
			v -= (p[i] - d[i]);
			i--; j--; //已经选了一个人了 
		}
	}
	printf("Best jury has value %d for prosecution and value %d for defence:\n", psum, dsum);
	sort(no, no + cnt);
	for (int i = 0 ; i < cnt; i++) {
		printf(" %d", no[i]);
	}
	printf("\n\n");
}

int main() {
	int cnt = 1;
	while (scanf("%d%d", &n, &m), n) {
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &p[i], &d[i]);
		}
		printf("Jury #%d\n", cnt++); 
		f();
	}
	return 0;
}
