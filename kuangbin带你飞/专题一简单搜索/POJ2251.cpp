#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int L, R, C;
int d[40][40][40];
char maze[40][40][40];
int dr[] = {0, 0, 1, -1, 0, 0};
int dc[] = {1, -1, 0, 0, 0, 0};
int dl[] = {0, 0, 0, 0, 1, -1};
// dfs超时，用bfs
// void dfs(int l, int r, int c, int t){
//     for(int i = 0; i < 6; i++){
//         bool in = (l + dl[i] >=0 && l + dl[i] < L && r + dr[i] >= 0 && r + dr[i] < R && c + dc[i] >= 0 && c + dc[i] < C);
//         if(in && maze[l+dl[i]][r+dr[i]][c+dc[i]] != '#'){
//             if(time[l+dl[i]][r+dr[i]][c+dc[i]] == 0 || time[l+dl[i]][r+dr[i]][c+dc[i]] > t + 1){
//                 time[l+dl[i]][r+dr[i]][c+dc[i]] = t + 1;
//                 dfs(l+dl[i], r+dr[i], c+dc[i], t + 1);
//             }
//             else continue;
//         }
//     }
// }
struct state{
    int l, r, c;
};
int main(){
    while(scanf("%d%d%d", &L, &R, &C) == 3 && L){
        // memset(time, 0, sizeof(time));
        int sl, sr, sc, el, er, ec;
        for(int i = 0; i < L; i++)
            for(int j = 0; j < R; j++){
                scanf("%s", maze[i][j]);
                for(int k = 0; k < C; k++){
                    d[i][j][k] = 0;
                    if(maze[i][j][k] == 'S') { sl = i; sr = j; sc = k; }
                    else if(maze[i][j][k] == 'E') { el = i; er = j; ec = k; }
                }
            }
        state s, next; s.l = sl; s.r = sr; s.c = sc;
        queue<state> q;
        q.push(s);
        // BFS
        while(!q.empty()){
            s = q.front(); q.pop();
            for(int i = 0; i < 6; i++){
                int newl = s.l + dl[i], newr = s.r + dr[i], newc = s.c + dc[i];
                bool in = (newl >= 0 && newl < L && newr >= 0 && newr < R && newc >= 0 && newc < C);
                if(in && maze[newl][newr][newc] != '#' && !d[newl][newr][newc]){
                    d[newl][newr][newc] = d[s.l][s.r][s.c] + 1;
                    next.l = newl; next.r = newr; next.c = newc;
                    if(next.l == el && next.r == er && next.c == ec) break;
                    q.push(next);
                }
            }
        }
        // dfs(sl, sr, sc, 0);
        if(d[el][er][ec] != 0) printf("Escaped in %d minute(s).\n", d[el][er][ec]);
        else printf("Trapped!\n");
    }

    return 0;
}