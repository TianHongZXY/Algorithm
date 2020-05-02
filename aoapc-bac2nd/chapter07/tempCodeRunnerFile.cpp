
#include<bits/stdc++.h>
using namespace std;
unordered_set<int> prime{2,3,5,7,11,13,17,19,23,29,31}; // 32内的素数
int n, vis[20]={0}, kcase=0;
vector<int> ans{1}; // 1先置入
void dfs(int cnt) { // cnt表示目前排列中已枚举的个数
    if (cnt == n && prime.count(1+ans.back())==1) { // 找到结果
        for (int i=0; i < ans.size(); i ++) printf("%d%s", ans[i], i == ans.size()-1 ? "\n" : " ");
    }
    else {
        for (int i=2; i <= n; i ++) { // 枚举2~n的全排列
            if (vis[i] == 0 && (prime.count(i+ans.back()) == 1)) { // 剪枝
                ans.push_back(i); vis[i] = 1; // 保存结果，标记已访问
                dfs(cnt+1); // 下一个
                ans.pop_back(); vis[i] = 0; // 退出最后一个结果，标记为未访问（回溯过程）
            }
        }
    }
}
int main() {
    while (scanf("%d", &n) == 1) {
        memset(vis, 0, sizeof(vis)); // 初始化
        if (kcase != 0) puts("");
        printf("Case %d:\n", ++kcase);
        dfs(1);
    }
    return 0;
}

