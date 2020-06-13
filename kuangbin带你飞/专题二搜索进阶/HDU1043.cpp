#include <iostream>
#include <cstring>
#include <cctype>
#include <queue>
using namespace std;
typedef int State[9];
// node1是记录了其父和从其父节点到达当前节点所做的操作
// node2是记录了每个状态对应的康托值
// 二者通过node2中的state_hash从states[]一一映射到node1
typedef struct nn1{
    char way;
    int father_hash = -1; // 该节点的父节点的康托展开值，也即其父在states[]中的索引值
}node1;
typedef struct nn2{
    State s;
    int z, state_hash; // z为x即0所在位置，state_hash为排列s对应的康拓展开值
}node2;
int fac[]= {1,1,2,6,24,120,720,5040,40320,362880};
// char path[] = {'r', 'l', 'd', 'u'}; // 移动的先后顺序不同也会导致路径不一，答案不唯一
char path[] = {'l', 'r', 'u', 'd'};

// int dx[] = {0, 0, -1, 1};
// int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
State goal  = {1,2,3,4,5,6,7,8,0}, init;
const int maxn = 370000;
node1 states[maxn];

int get_hash(State s){
    // 康拓展开对全排列进行一一映射
    int sum = 0;
    for(int i = 0; i < 9; i++){
        int num = 0;
        for(int j = i + 1; j < 9; j++)
            if(s[j] < s[i]) num++;
        sum += (num * fac[9 - i - 1]);
    }
    return sum + 1;
}

void bfs(){
    queue<node2> Q;
    node2 p, q;
    for(int i = 0; i < 9; i++) q.s[i] = goal[i]; // 初始化q为goal
    q.state_hash = get_hash(q.s);
    q.z = 8;
    states[q.state_hash].father_hash = -2; // 令goal状态对应的hash的父hash为-2
    Q.push(q);
    while(!Q.empty()){
        q = Q.front(); Q.pop();
        int x = q.z / 3, y = q.z % 3;
        for(int i = 0; i < 4; i++){
            int newx = x + dx[i], newy = y + dy[i];
            if(newx >= 0 && newx < 3 && newy >= 0 && newy < 3){
                p = q;
                int newz = newx * 3 + newy;
                p.z = newz;
                p.s[p.z] = 0;
                p.s[q.z] = q.s[p.z];
                p.state_hash = get_hash(p.s);
                if(states[p.state_hash].father_hash == -1){
                    states[p.state_hash].father_hash = q.state_hash;
                    states[p.state_hash].way = path[i];
                    Q.push(p);
                }
            }
        }
    }
}
int main(){
    // for(int i = 0; i < maxn; i++)
    //     states[i].father_hash = -1;
    bfs();
    char line[150];
    while(cin.getline(line, 100, '\n')){
        int n = strlen(line);
        int cur = 0;
        for(int i = 0; i < n; i++){
            if(isdigit(line[i])){
                init[cur++] = line[i] - '0';
            }
            else if(line[i] == 'x'){
                init[cur++] = 0;
            }
            else continue;
        }
        int init_hash = get_hash(init);
        if(states[init_hash].father_hash == -1){
            cout << "unsolvable" << endl;
        }
        else{
            while(states[init_hash].father_hash != -2){
                cout << states[init_hash].way;
                init_hash = states[init_hash].father_hash;
            }
            cout << endl;
        }
    }
    return 0;
}