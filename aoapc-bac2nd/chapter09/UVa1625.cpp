#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF (1<<30)
using namespace std;
const int maxn = 5000 + 50;
int d[maxn][maxn], cnt[maxn][maxn], ss1[26], es1[26], ss2[26], es2[26];
char s1[maxn], s2[maxn];

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%s%s", s1+1, s2+1);
        int n1 = strlen(s1+1), n2 = strlen(s2+1);
        for(int i = 1; i <= n1; i++) s1[i] -= 'A';
        for(int i = 1; i <= n2; i++) s2[i] -= 'A';
        for(int i = 0; i <= 25; i++){ // 所有字符的开始设为无穷，结束设为0
            ss1[i] = INF; es1[i] = 0;
            ss2[i] = INF; es2[i] = 0;
        }
        for(int i = 1; i <= n1; i++){ // 初始化开始与结束数组
            ss1[s1[i]] = min(ss1[s1[i]], i);
            es1[s1[i]] = i;
        }
        for(int i = 1; i <= n2; i++){
            ss2[s2[i]] = min(ss2[s2[i]], i);
            es2[s2[i]] = i;
        }
        for(int i = 0; i <= n1; i++)
            for(int j = 0; j <= n2; j++){
                if(i && !j){ // 如果j也大于0，对cnt[i][j]做的变动就被下面的if(j)覆盖了(二者等效)，所以只有i>0且j等于0才做
                    cnt[i][j] = cnt[i-1][j]; // cnt[i][j]为从ss1中选前i个，ss2中选前j个后，有多少种颜色在新合并的字符串里已出现，且还未在ss1与ss2中结束
                    // 选取s1[i]到新合并字符串中
                    if(ss1[s1[i]] == i && ss2[s1[i]] > j) cnt[i][j]++; // 如果ss1[i]是新合并的字符串里没出现过的字符(第一次从ss1中选出来，且在ss2中还没结束)，那么之后的开销+1
                    if(es1[s1[i]] == i && es2[s1[i]] <= j) cnt[i][j]--; // 如果ss1[i]这个颜色是在ss1里中最后一次出现，且其在ss2中已经被完全选到了新合并字符串，那么之后的开销-1
                }
                if(j){
                    cnt[i][j] = cnt[i][j-1];
                    if(ss2[s2[j]] == j && ss1[s2[j]] > i) cnt[i][j]++;
                    if(es2[s2[j]] == j && es1[s2[j]] <= i) cnt[i][j]--;
                }
            }
        for(int i = 0; i <= n1; i++)
            for(int j = 0; j <= n2; j++){
                if(!i && !j) continue;
                int v1 = INF, v2 = INF;
                if(i) v1 = d[i-1][j] + cnt[i-1][j]; // 从d[i-1][j]转移到d[i][j]，即选ss1[i]
                if(j) v2 = d[i][j-1] + cnt[i][j-1]; // 从d[i][j-1]转移到d[i][j]，即选ss2[j]
                d[i][j] = min(v1, v2);
            }
        printf("%d\n", d[n1][n2]);
    }

    return 0;
}