#include <cstdio>
#include <string>
using namespace std;
int n, m, x, y;
int vis[105];

int main(){
    scanf("%d%d%d%d", &n, &m, &x, &y);
    if(y == 1){
        for(int i = 1; i <= m; i++)
            if(i == y) continue;
            else printf("%d %d\n", x, i);
    }
    else{
        for(int i = m; i >= 1; i--)
            if(i == y) continue;
            else printf("%d %d\n", x, i);
    }
    int start;
    if(y == 1) start = m;
    else start = 1;
    vis[x] = 1;
    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;
        if(start == 1){
            for(int j = 1; j <= m; j++)
                printf("%d %d\n", i, j);
            start = m;
        }
        else{
            for(int j = m; j >= 1; j--)
                printf("%d %d\n", i, j);
            start = 1;
        }
        vis[i] = 1;
    }

    return 0;
}