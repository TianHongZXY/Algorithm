// UVa1601 The Morning after Halloween
// Rujia Liu
// This code implements the simpliest yet efficient-enough algorithm I'm aware of
// Readers are encouraged to experiment on other algorithms (especially for better efficiency!)
#include<cstdio>
#include<cstring>
#include<cctype>
#include<queue>
using namespace std;

const int maxs = 20;
const int maxn = 150; // 75% cells plus 2 fake nodes
const int dx[]={1,-1,0,0,0}; // 4 moves, plus "no move"
const int dy[]={0,0,1,-1,0};

inline int ID(int a, int b, int c) { // 这里的inline是干嘛的？
  return (a<<16)|(b<<8)|c; // 二进制子集 因为abc是编号，且编号小于150，所以用8位二进制就能编码一个
}

int s[3], t[3]; // starting/ending position of each ghost

int deg[maxn], G[maxn][5]; // target cells for each move (including "no move")

inline bool conflict(int a, int b, int a2, int b2) {
  return a2 == b2 || (a2 == b && b2 == a); // 不能a的目标点a2是b 且b的目标点b2是a 因为发生了一步交换， 也不能目标点一致
}

int d[maxn][maxn][maxn]; // distance from starting state

int bfs() {
    queue<int> q;
    memset(d, -1, sizeof(d));
    q.push(ID(s[0], s[1], s[2])); // starting node
    d[s[0]][s[1]][s[2]] = 0; // s为三个ghost的编号
    while(!q.empty()) {
      int u = q.front(); q.pop();
      int a = (u>>16)&0xff, b = (u>>8)&0xff, c = u&0xff;
      if(a == t[0] && b == t[1] && c == t[2]) return d[a][b][c]; // solution found
      for(int i = 0; i < deg[a]; i++) {
        int a2 = G[a][i];
        for(int j = 0; j < deg[b]; j++) {
          int b2 = G[b][j];
          if(conflict(a, b, a2, b2)) continue;
          for(int k = 0; k < deg[c]; k++) {
            int c2 = G[c][k];
            if(conflict(a, c, a2, c2)) continue;
            if(conflict(b, c, b2, c2)) continue;
            if(d[a2][b2][c2] != -1) continue; // 如果a2b2c2这个状态之前就有过了 跳过
            d[a2][b2][c2] = d[a][b][c]+1; // 没出现过状态，等于上一步的距离+1
            q.push(ID(a2, b2, c2));
          }
        }
      }
    }
  return -1;
}

int main() {
  int w, h, n; 

  while(scanf("%d%d%d\n", &w, &h, &n) == 3 && n) {
    char maze[20][20];
    for(int i = 0; i < h; i++)
      fgets(maze[i], 20, stdin);

    // extract empty cells
    int cnt, x[maxn], y[maxn], id[maxs][maxs]; // cnt is the number of empty cells
    cnt = 0;
    for(int i = 0; i < h; i++)
      for(int j = 0; j < w; j++)
        if(maze[i][j] != '#') {
          x[cnt] = i; y[cnt] = j; id[i][j] = cnt;  // id[i][j]是地图上不为墙的点的编号cnt, x[cnt]可得该编号的点的横坐标
          if(islower(maze[i][j])) s[maze[i][j] - 'a'] = cnt;
          else if(isupper(maze[i][j])) t[maze[i][j] - 'A'] = cnt;
          cnt++;
        }

    // build a graph of empty cells
    for(int i = 0; i < cnt; i++) {
      deg[i] = 0; // deg[i]是编号为i的位置可移动方向的个数
      for(int dir = 0; dir < 5; dir++) {
        int nx = x[i]+dx[dir], ny = y[i]+dy[dir]; // x[i]为编号为i的点横坐标
        // "Outermost cells of a map are walls" means we don't need to check out-of-bound
        // 如果地图上(nx, ny)的点不为墙，则编号为i的点可移动方向数目+1，且该步到达的点编号为id[nx][ny]
        if(maze[nx][ny] != '#') G[i][deg[i]++] = id[nx][ny]; 
      }
    }

    // add fakes nodes so that in each case we have 3 ghosts. this makes the code shorter
    if(n <= 2) { deg[cnt] = 1; G[cnt][0] = cnt; s[2] = t[2] = cnt++; } // 可移动的方向就一个，且移动完还是自己，等于不动
    if(n <= 1) { deg[cnt] = 1; G[cnt][0] = cnt; s[1] = t[1] = cnt++; } // 起点和终点一致，不会发生移动

    printf("%d\n", bfs());
  }
  return 0;
}
