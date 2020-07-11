// dfs做法，AC
#include <cstdio>
#include <cstring>
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
int num[5], cash[5] = {0, 1, 5, 10, 25};
int ans, P;
bool dfs(int n, int sum, int idx){
    if(sum == P) { ans = n; return true; }
    if(sum > P || idx > 4) return false;
    int high = min(num[idx], (P - sum) / cash[idx]);
    int low = max(0, high - 25); // 关键，否则超时！low为什么取high-25？最大面额为25，把前面的某一个面额转换成后面的面额时，最多消耗25个小面额即可。
    for(int i = high; i >= low; i--){
        if(dfs(n + i, sum + i * cash[idx], idx + 1)) return true;
    }
    return false;
}

int main(){
    scanf("%d%d%d%d%d", &P, &num[1], &num[2], &num[3], &num[4]);
    if(dfs(0, 0, 1)) printf("%d", ans);
    else printf("Impossible");
    
    return 0;
}