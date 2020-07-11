#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
const int maxn = 25;
const int maxm = 105;
const int maxs = 1e7;
typedef char State[maxn];
int n, m;
State goal;
map<int, int> code2idx;

struct Edge{
    int t;
    char from[maxn], to[maxn];
    bool operator < (const Edge& rhs) const{
        return t < rhs.t;
    }
}edges[maxm];

struct Node{
    State s;
    int t, idx, code;
    bool operator > (const Node& rhs) const{
        return t > rhs.t;
    }
}st[maxs];

void init_lookup_table(){
    code2idx.clear();
}

bool cantransfer(Node& node, int e){
    for(int i = 0; i < n; i++){
        if(edges[e].from[i] == '0') continue;
        if(edges[e].from[i] != node.s[i]) return false;
    }
    return true;
}

int get_code(Node& node){
    int code = 0;
    for(int i = 0; i < n; i++){
        code = code * 10 + (node.s[i] - '+');
    }
    return code;
}

bool try_to_insert(Node& node){
    if(code2idx.count(node.code)){
        if(st[code2idx[node.code]].t > node.t)
            return true;
        else return false;
    }
    return true;
}

int main(){
    int t, kase = 0;
    char from[maxn], to[maxn];
    while(scanf("%d%d", &n, &m) == 2 && (n || m)){
        for(int i = 0; i < m; i++)
            scanf("%d %s %s", &edges[i].t, edges[i].from, edges[i].to);
        sort(edges, edges + m);
        priority_queue<Node, vector<Node>, greater<Node> > Q;
        for(int i = 0; i < n; i++) goal[i] = '-';
        int front = 1, rear = 2;
        for(int i = 0; i < n; i++) st[front].s[i] = '+';
        st[front].idx = front; st[front].t = 0; code2idx[get_code(st[front])] = front;
        Q.push(st[front]); // TODO
        Node *ans = NULL;
        while(!Q.empty()){
            Node cur = Q.top(); Q.pop();
            if(memcmp(goal, cur.s, sizeof(goal[0]) * n) == 0) { ans = &cur; break; }
            for(int i = 0; i < m; i++)
                if(cantransfer(cur, i)){
                    Node &next = st[rear];
                    for(int j = 0; j < n; j++){
                        next.s[j] = (edges[i].to[j] == '0' ? cur.s[j] : edges[i].to[j]);
                    }
                    next.t = cur.t + edges[i].t; next.idx = rear; next.code = get_code(next);
                    if(try_to_insert(next)){
                        code2idx[next.code] = rear++;
                        Q.push(next);
                    }
                }
        }
        printf("Product %d\n", ++kase);
        if(ans != NULL){
            printf("Fastest sequence takes %d seconds.\n", ans->t);
        }
        else
            printf("Bugs cannot be fixed.\n");
        printf("\n");
        init_lookup_table();
    }
    return 0;
}