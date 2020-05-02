#include <cstdio>
#include <cctype>
#include <cstring>
#include <queue>
using namespace std;
const int maxs = 20;
const int maxn = 150;
int G[maxn][5], deg[maxn]; 
int x[maxn], y[maxn], id[maxs][maxs];
int s[3], t[3];
int dx[] = {-1, 1, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0};
int dist[maxn][maxn][maxn]; // 索引是三个鬼所在点的编号，值是初始状态到达该状态的距离

bool conflict(int a, int b, int a2, int b2){
    return a2 == b2 || (a2 == b && b2 == a); // 起始a b两点的目标点编号a2 b2不能相同，也不能发生一步内交换
}

int ID(int a, int b, int c){ // 二进制法，将三点的编号编码为唯一的数字，使各状态有不同编码
    return (a<<16)|(b<<8)|c;
}

int bfs(){
    dist[s[0]][s[1]][s[2]] = 0; // 初始状态
    queue<int> q;
    q.push(ID(s[0], s[1], s[2]));
    while(!q.empty()){
        int u = q.front(); q.pop();
        int a = (u>>16)&0xff, b = (u>>8)&0xff, c = u&0xff;
        if(a == t[0] && b == t[1] && c == t[2]) return dist[a][b][c];
        for(int i = 0; i < deg[a]; i++){ // 非墙点的deg最小是1，因为保持不动也是一个移动方式
            int a2 = G[a][i];
            for(int j = 0; j < deg[b]; j++){
                int b2 = G[b][j];
                if(conflict(a, b, a2, b2)) continue;
                for(int k = 0; k < deg[c]; k++){
                    int c2 = G[c][k];
                    if(conflict(a, c, a2, c2)) continue;
                    if(conflict(b, c, b2, c2)) continue;
                    if(dist[a2][b2][c2] != -1) continue; // 如果该状态之前就有过 跳过
                    dist[a2][b2][c2] = dist[a][b][c] + 1;
                    q.push(ID(a2, b2, c2));
                }
            }
        }
    }
    return -1;
}

int main(){
    int w, h, n;
    while(scanf("%d%d%d\n", &w, &h, &n)==3 && w){
        memset(dist, -1, sizeof(dist)); // -1表示没有该状态
        memset(deg, 0, sizeof(deg));
        memset(id, -1, sizeof(id)); // -1表示id[i][j]为墙
        char maze[20][20];
        for(int i = 0; i < h; i++)
            fgets(maze[i], 20, stdin);
        int cnt = 0;
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++) if(maze[i][j] != '#'){
                x[cnt] = i; y[cnt] = j; id[i][j] = cnt;
                if(islower(maze[i][j])) s[maze[i][j] - 'a'] = cnt;
                else if(isupper(maze[i][j])) t[maze[i][j] - 'A'] = cnt;
                cnt++;
            }
        for(int i = 0; i < cnt; i++) // 遍历每个非墙点
            for(int j = 0; j < 5; j++) // 遍历其上下左右不动的位置
                if(id[x[i]+dx[j]][y[i]+dy[j]] != -1){ // 若其周围某一点非墙
                    G[i][deg[i]++] = id[x[i]+dx[j]][y[i]+dy[j]]; // 编号i的点到达的点编号，可移动方向+1，
            }
        if(n <= 2) { deg[cnt] = 1; G[cnt][0] = cnt; s[2] = t[2] = cnt++; } // 可移动的方向就一个，且移动完还是自己，等于不动
        if(n <= 1) { deg[cnt] = 1; G[cnt][0] = cnt; s[1] = t[1] = cnt++; } // 起点和终点一致，不会发生移动

        printf("%d\n", bfs());
    }
    return 0;
}
