#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct Node{
    int v[3], dist;
    bool operator < (const Node& rhs) const{
        return dist > rhs.dist; // dist大的反而小，dist最小的被放在优先队列的最上面
    }
};
const int maxn = 200 + 5;
int vis[maxn][maxn], cap[3], ans[maxn];

void update_ans(const Node& u){
    for(int i = 0; i < 3; i++){ // 遍历当前状态的三个杯子
        int d = u.v[i];
        if(ans[d] < 0 || u.dist < ans[d]) ans[d] = u.dist; // 如果该杯子装的水在ans中没出现或该状态的dist更小
    }
}

void solve(int a, int b, int c, int d){
    cap[0] = a; cap[1] = b; cap[2] = c;
    memset(vis, 0, sizeof(vis));
    memset(ans, -1, sizeof(ans));
    priority_queue<Node> q;

    Node start;
    start.dist = 0; start.v[0] = 0; start.v[1] = 0; start.v[2] = c;
    q.push(start);
    vis[0][0] = 1;
    while(!q.empty()){
        Node u = q.top(); q.pop();
        update_ans(u);
        if(ans[d] >= 0) break;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++) if(i != j){ // 把v[i]里的水导入v[j]
                if(u.v[i] == 0 || u.v[j] == cap[j]) continue; // 如果v[i]没水或v[j]满了 跳过
                int amount = min(cap[j], u.v[i] + u.v[j]) - u.v[j];  // 从v[i]倒了amount升水到v[j]
                Node u2;
                memcpy(&u2, &u, sizeof(u));
                u2.dist = u.dist + amount;
                u2.v[i] -= amount; u2.v[j] += amount;
                if(!vis[u2.v[0]][u2.v[1]]){ // 因为v[0]和v[1]确定后，状态三元组就确定了, v[2] = c - v[0] - v[1]
                    vis[u2.v[0]][u2.v[1]] = 1;
                    q.push(u2);
                }
            }
    }
    while(d >= 0){
        if(ans[d] >= 0) {
            printf("%d %d\n", ans[d], d);
            return;
        }
        d--;
    }
}

int main(){
    int T, a, b, c, d;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d%d", &a, &b, &c, &d);
        solve(a, b, c, d);
    }
    return 0;
}