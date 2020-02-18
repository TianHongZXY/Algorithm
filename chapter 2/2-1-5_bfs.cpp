#include <utility>
#include <queue>
#include <iostream>

using namespace std;

const int INF = 100000000;
const int MAX_N = 100, MAX_M = 100;
typedef pair<int, int> P;

char maze[MAX_N][MAX_M + 1];
int N, M;
int sx, sy;
int gx, gy;


int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int bfs(){
    int d[MAX_N][MAX_M];
    for (int i = 0; i < N; i++)
        for( int j = 0; j < N; j++)
            d[i][j] = INF;
    queue<P> que;
    que.push(P(sx, sy));
    d[sx][sy] = 0;

    while (que.size()){
        P p = que.front(); que.pop();
        if (p.first == gx && p.second == gy) break;

        for (int i = 0; i < 4; i++){
            int nx = p.first + dx[i], ny = p.second + dy[i];

            if (0 <= nx && nx < N && 0 <= ny && ny <= M && maze[nx][ny] != '#'
                && d[nx][ny] == INF){
                    que.push(P(nx, ny));
                    d[nx][ny] = d[p.first][p.second] + 1;
                }
        }
    }
    return d[gx][gy];
}

void solve(){
    int res = bfs();
    cout << res << endl;
}

int main(int argc, char const *argv[])
{
    printf("Input N and M: ");
    cin >> N >> M;
    printf("Input sx sy and gx gy: ");
    cin >> sx >> sy >> gx >> gy;
    printf("Input maze: ");
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++){
            cin >> maze[i][j];
        }
    solve();
    return 0;
}
