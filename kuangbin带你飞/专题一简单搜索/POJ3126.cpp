#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
const int maxn = 10000 + 10;
int step[maxn], vis[maxn], primes[maxn];

int is_prime(int x){
    double upbound = sqrt(1.0*x);
    for(int i = 2; i <= upbound; i++){
        if(x % i == 0) return 0;
    }
    return 1;
}

void save_primes(){
    for(int i = 1000; i <= 9999; i++){
        if(is_prime(i)) primes[i] = 1;
    }
}

int try_to_insert(int next, int cur){
    if(!vis[next] && primes[next]){
        vis[next] = 1;
        step[next] = step[cur] + 1;
        return 1;
    }
    return 0;
}
int solve(int src, int dst){
    vis[src] = 1; step[src] = 0;
    queue<int> q;
    q.push(src);
    int cur;
    while(!q.empty()){
        cur = q.front(); q.pop();
        if(cur == dst) break;
        int qian = cur / 1000; 
        int bai = (cur % 1000) / 100;
        int shi = (cur % 100) / 10; 
        int ge = cur % 10;        
        for(int i = 0; i <= 9; i++){
            if(i == ge) continue;
            int next = qian * 1000 + bai * 100 + shi * 10 + i;
            if(try_to_insert(next, cur)){
                if(next == dst) return step[next];
                q.push(next);
            }
        }
        for(int i = 0; i <= 9; i++){
            if(i == shi) continue;
            int next = qian * 1000 + bai * 100 + i * 10 + ge;
            if(try_to_insert(next, cur)){
                if(next == dst) return step[next];
                q.push(next);
            }
        }
        for(int i = 0; i <= 9; i++){
            if(i == bai) continue;
            int next = qian * 1000 + i * 100 + shi * 10 + ge;
            if(try_to_insert(next, cur)){
                if(next == dst) return step[next];
                q.push(next);
            }
        }
        for(int i = 1; i <= 9; i++){
            if(i == qian) continue;
            int next = i * 1000 + bai * 100 + shi * 10 + ge;
            if(try_to_insert(next, cur)){
                if(next == dst) return step[next];
                q.push(next);
            }
        }
    }
    if(vis[dst]) return step[dst];
    else return -1;
}

int main(){
    int n, src, dst;
    save_primes();
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> src >> dst;
        memset(vis, 0, sizeof(vis));
        int cost = solve(src, dst);
        if(cost != -1) cout << cost << endl;
        else cout << "Impossible" << endl;
    }

    return 0;
}