#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <queue>
#include <set>
using namespace std;
typedef int State[9];
const int maxn = 400000;
State init_goal[2], st[maxn];
int pre[maxn], aft[maxn];
char line[100], op1[maxn], op2[maxn], path[] = {'d', 'l', 'r', 'u'}, path_rev[] = {'u', 'r', 'l', 'd'};
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
int front, rear, init_hash, goal_hash;
int fac[]= {1,1,2,6,24,120,720,5040,40320,362880};
// int vis[maxn];
char solution1[10000], solution2[10000];

int get_hash(State s){
    int sum = 0;
    for(int i = 0; i < 9; i++){
        int num = 0;
        for(int j = i + 1; j < 9; j++)
            if(s[j] < s[i]) num++;
        sum += (num * fac[9 - i - 1]);
    }
    return sum + 1;
}

// void init_lookup_table(){ memset(vis, 0, sizeof(vis)); }

// int try_to_insert(State s, int v){
//     if(!vis[v]){
//         vis[v] = 1;
//         memcpy(st[v], s, sizeof(st[v]));
//         return 1;
//     }
//     return 0;
// }   

int bfs(){
    set<int> q1vis, q2vis, vis_;
    int flag = 0; // flag为0从起点开始，flag为1从终点开始
    // q1.push(init_hash); q2.push(goal_hash);
    q1vis.insert(init_hash); q2vis.insert(goal_hash); //q1.insert(init_hash); q2.insert(goal_hash);
    while(!q1vis.empty() && !q2vis.empty()){
        set<int> temp;
        for(auto cur_hash : q1vis){
            if(q2vis.count(cur_hash)){
                if(!flag) return cur_hash;
                else break;
            }
            vis_.insert(cur_hash);
            State& stat = st[cur_hash];
            int z;
            for(z = 0; z < 9; z++) if(!stat[z]) break;
            int x = z / 3, y = z % 3;
            if(!flag){
                for(int i = 0; i < 4; i++){
                    int newx = x + dx[i], newy = y + dy[i];
                    if(newx >= 0 && newx < 3 && newy >= 0 && newy < 3){
                        int newz = newx * 3 + newy;
                        State next;
                        memcpy(next, stat, sizeof(next));
                        next[newz] = stat[z];
                        next[z] = stat[newz];
                        int next_hash = get_hash(next);
                        if(vis_.count(next_hash)) continue;
                        pre[next_hash] = cur_hash;
                        op1[next_hash] = path[i];
                        temp.insert(next_hash);
                        memcpy(st[next_hash], next, sizeof(st[next_hash]));
                    }
                }
            }
            else{
                for(int i = 3; i >= 0; i--){
                    int newx = x + dx[i], newy = y + dy[i];
                    if(newx >= 0 && newx < 3 && newy >= 0 && newy < 3){
                        int newz = newx * 3 + newy;
                        State next;
                        memcpy(next, stat, sizeof(next));
                        next[newz] = stat[z];
                        next[z] = stat[newz];
                        int next_hash = get_hash(next);
                        if(vis_.count(next_hash)) continue;
                        aft[next_hash] = cur_hash;
                        op2[next_hash] = path_rev[i];
                        temp.insert(next_hash);
                        memcpy(st[next_hash], next, sizeof(st[next_hash]));
                    }
                }
            }
        }
        flag ^= 1;
        q1vis = q2vis;
        q2vis = temp;
    }
    return 0;
}

int main(){
    int n, T, kase = 0;
    char line[20];
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        for(int k = 0; k < 2; k++){
            scanf("%s", line);
            for(int j = 0; line[j] != '\0'; j++){
                if(isdigit(line[j]))
                    init_goal[k][j] = line[j] - '0';
                else init_goal[k][j] = 0;
            }
        }
        init_hash = get_hash(init_goal[0]);
        goal_hash = get_hash(init_goal[1]);
        // front = 1, rear = 2;
        memcpy(st[init_hash], init_goal[0], sizeof(st[1]));
        memcpy(st[goal_hash], init_goal[1], sizeof(st[1]));
        pre[init_hash] = -1; aft[goal_hash] = -1;
        // init_lookup_table();
        // vis[init_hash] = 1; vis[goal_hash] = 1;
        int retrn = bfs();
        if(!retrn){
            std::cout << "unsolvable" << endl;
            continue;
        }
        int len1 = 0, len2 = 0, length = 0;
        int solv = retrn;
        while(pre[solv] != -1){
            solution1[len1++] = op1[solv];
            solv = pre[solv];
        }
        length += len1;
        std::cout << "Case " << ++kase << ": ";
        solv = retrn;
        while(aft[solv] != -1){
            solution2[len2++] = op2[solv];
            solv = aft[solv];
        }
        length += len2;
        std::cout << length << endl;
        for(int i = len1 - 1; i >= 0; i--)
            std::cout << solution1[i];
        for(int i = 0; i < len2; i++)
            std::cout << solution2[i];
        std::cout << endl;
    }
    return 0;
}