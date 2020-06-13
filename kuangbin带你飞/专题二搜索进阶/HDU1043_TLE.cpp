#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <set>
using namespace std;
typedef int State[9];
const int maxn = 400000;
State goal  = {1,2,3,4,5,6,7,8,0} , st[maxn], init;
int pre[maxn];
char line[100], op[maxn], path[] = {'l', 'r', 'u', 'd'};
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int front, rear, ans_hash;
int fac[]= {1,1,2,6,24,120,720,5040,40320,362880};
int vis[400000];
char solution[10000];

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

void init_lookup_table(){ memset(vis, 0, sizeof(vis)); }

int try_to_insert(State s){
    int v = get_hash(s);
    // for(int i = 0; i < 9; i++) v = v * 10 + s[i];
    if(!vis[v]){
        vis[v] = 1;
        return 1;
    }
    return 0;
}   

int bfs(){
    while(front < rear){
        State& stat = st[front];
        int stat_hash = get_hash(stat);
        if(stat_hash == ans_hash) return front;
        int z;
        for(z = 0; z < 9; z++) if(!stat[z]) break;
        int x = z / 3, y = z % 3;
        for(int i = 0; i < 4; i++){
            int newx = x + dx[i], newy = y + dy[i];
            if(newx >= 0 && newx < 3 && newy >= 0 && newy < 3){
                int newz = newx * 3 + newy;
                State& next = st[rear];
                memcpy(next, stat, sizeof(next));
                next[newz] = stat[z];
                next[z] = stat[newz];
                if(try_to_insert(next)){
                    pre[rear] = front;
                    op[rear] = path[i];
                    rear++;
                }
            }
        }
        front++;
    }
    return -1;
}

int main(){
    int n;
    ans_hash = get_hash(goal);
    while(cin.getline(line, 100, '\n')){
        int n = strlen(line);
        int cur = 0;
        front = 1, rear = 2;
        for(int i = 0; i < n; i++){
            if(isdigit(line[i])){
                init[cur++] = line[i] - '0';
            }
            else if(line[i] == 'x'){
                init[cur++] = 0;
            }
            else continue;
        }
        memcpy(st[1], init, sizeof(st[1]));
        pre[1] = -1;
        init_lookup_table();
        try_to_insert(st[1]);
        int front = bfs();
        if(front == -1){
            cout << "unsolvable" << endl;
            continue;
        }
        int len = 0;
        while(front != -1){
            solution[len++] = op[front];
            front = pre[front];
        }
        for(int i = len - 1; i >= 0; i--)
            cout << solution[i];
    }
    return 0;
}