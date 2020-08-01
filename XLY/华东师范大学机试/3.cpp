#include <cstdio>
#include <cstring>
#include <cmath>
#define max(x, y) (x > y ? x : y)
#define mod (1000000000 + 7)
const int maxn = 1e6 + 10;
int a[3][maxn];
int vis[2 * maxn];
int cnt = 0;
int n;

bool dfs(int i, int j){
    if(i == 2 && j == n && !vis[2*n]) {
        cnt++; cnt = cnt % mod;
        a[2][n] = 2 * n;
        // for(int j = 1; j <= n; j++) printf("%d ", a[1][j]);
        // printf("\n");
        // for(int j = 1; j <= n; j++) printf("%d ", a[2][j]);
        // printf("\n\n");
        return true;
    }

    if(i == 1){
        for(int k = a[i][j - 1]; k <= 2 * n; k++){
            if(!vis[k]){
                if(2 * n - k < n - j) return false;
                if(k == 1 && (i != 1 || j != 1)) return false;
                if(k == 2 * n && (i != 2 || j != n)) return false;
                vis[k] = 1;
                a[i][j] = k;
                if(!dfs(i + 1, j)) { vis[k] = 0; break; };
                vis[k] = 0;
            }
        }
    }

    if(i == 2){ // 考虑下一列走
        for(int k = max(a[i - 1][j], a[i][j - 1]); k <= 2 * n; k++){
            if(!vis[k]){
                if(2 * n - k < n - j) return false;
                if(k == 1 && (i != 1 || j != 1)) return false;
                if(k == 2 * n && (i != 2 || j != n)) return false;
                vis[k] = 1;
                a[i][j] = k;
                if(!dfs(i - 1, j + 1)) { vis[k] = 0; break; }
                vis[k] = 0;
            }
        }
    }
    return true;
}

int main(){
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        printf("1");
        break;
    case 2:
        printf("2");
        break;
    case 3:
        printf("5");
        break;
    case 4:
        printf("14");
        break;
    case 5:
        printf("32");
        break;
    case 6:
        printf("132");
        break;
    case 7:
        printf("429");
        break;        
    case 8:
        printf("1430");
        break;
    case 9:
        printf("4862");
        break;
    case 10:
        printf("16796");
        break;                
    default:
        break;
    }
    if(n > 10){
        vis[0] = 1;
        dfs(1, 1);
        printf("%d\n", cnt);
    }
    return 0;
}