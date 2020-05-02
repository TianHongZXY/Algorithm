#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
typedef int State[9]; // State是一个int[9]类型
const int maxnstate = 1000000;
State st[maxnstate], goal; // st存储maxnstate个状态，每个状态是一个int[9]
int dist[maxnstate];
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

set<int> vis;
void init_lookup_table(){ vis.clear(); }

int try_to_insert(int s){
    int v = 0;
    for(int i = 0; i < 9; i++) v = v * 10 + st[s][i]; // v相当于是0~8的一个排列，比如 012345678
    if(vis.count(v)) return 0;
    vis.insert(v);
    return 1;
}

int bfs(){
    init_lookup_table();
    int front = 1, rear = 2;
    while(front < rear){
        State& s = st[front]; // 取出队列头的一个状态
        if(memcmp(goal, s, sizeof(s)) == 0) return front;
        int z;
        for(z = 0; z < 9; z++) if(!s[z]) break; // 找到空格，即 '0' 的位置
        int x = z / 3, y = z % 3; // x是行，y是列 都是 0 ~ 2
        for(int d = 0; d < 4; d++){
            int newx = x + dx[d], newy = y + dy[d];
            int newz = newx * 3 + newy;
            if(newx >= 0 && newx < 3 && newy >= 0 && newy < 3){
                State& t = st[rear]; // st[rear]将是从st[front]出发得到的新状态
                memcpy(&t, &s, sizeof(s)); // 把复制s到t中
                t[newz] = s[z]; // 在t中将原s[z]和s[newz]互换位置
                t[z] = s[newz]; 
                dist[rear] = dist[front] + 1; // 新结点离顶层的距离，即要移动的步数
                if(try_to_insert(rear)) rear++; // 判断当前的状态t是否出现过，没有重复出现则rear++
            }
        }
        front++;
    }
}

int main(){
    for(int i = 0; i < 9; i++) scanf("%d", &st[1][i]);
    for(int i = 0; i < 9; i++) scanf("%d", &goal[i]);
    int ans = bfs();
    if(ans > 0) printf("%d\n", dist[ans]);
    else printf("-1\n");
    return 0;
}