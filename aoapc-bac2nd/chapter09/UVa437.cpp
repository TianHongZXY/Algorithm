#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 30 + 5;
int dim[maxn][3], d[maxn][3];
int n;

void get_dimention(int* v, int b, int axis){
    int idx = 0;
    for(int i = 0; i < 3; i++) if(i != axis) v[idx++] = dim[b][i];
}

int dp(int i, int k){
    int& ans = d[i][k];
    if(ans > 0) return d[i][k];
    ans = 0;
    int v[2], v2[2], subans = 0;
    get_dimention(v, i, k);
    for(int j = 0; j < n; j++){
        for(int k2 = 0; k2 < 3; k2++){
            get_dimention(v2, j, k2);
            if(v[0] < v2[0] && v[1] < v2[1])
                subans = max(subans, dp(j, k2));
        }
    }
    ans += subans + dim[i][k];
    return ans;
}

int main(){
    int kase = 0;
    while(scanf("%d", &n) == 1 && n){
        memset(d, -1, sizeof(d));
        for(int i = 0; i < n; i++){
            scanf("%d%d%d", &dim[i][0], &dim[i][1], &dim[i][2]);
            sort(dim[i], dim[i] + 3);
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int k = 0; k < 3; k++)
                ans = max(ans, dp(i, k));
        printf("Case %d: maximum height = %d\n", ++kase, ans);
    }
    return 0;
}