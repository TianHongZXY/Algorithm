#include <cstdio>
const int maxn = 100 + 5;
int map[maxn][maxn], vis[maxn][maxn];
int len = 0;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int n, m;

bool inmap(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < m);
}
void dfs(int x, int y){
    int contri = 4;
    if(vis[x][y]) return;
    else vis[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(inmap(xx, yy) && map[xx][yy]){
            contri--;
            if(!vis[xx][yy])
                dfs(xx, yy);
        }
    }
    len += contri;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &map[i][j]);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(map[i][j] == 1){
                dfs(i, j);
                printf("%d", len);
                return 0;
            }
        }

    return 0;
}


// 解法二
/* #include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 110;
int map[maxn][maxn] = {0};
int dx[4] = {0, 0, 1, -1}; // x y的邻接位置的4个方向
int dy[4] = {1, -1, 0, 0};

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int ans = 0;
    for(int i=1; i<=n; i++) // 从1开始，给地图外框加一圈0，作为边界
    {
        for(int j=1; j<=m; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    for(int x=1; x<=n; x++)
    {
        for(int y=1; y<=m; y++)
        {
            if(map[x][y] == 1)
            {
                for(int k=0; k<4; k++)
                {
                    if(map[x+dx[k]][y+dy[k]] == 0) // 陆地的四周有几面是海，该块陆地的周长就是几
                    {
                        ans++;
                    }
                }
            }
        }
    }
    printf("%d", ans);

    return 0;
}
*/

