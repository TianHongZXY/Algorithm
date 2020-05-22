#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 100000 + 10;
int step[maxn], vis[maxn];

int main(){
    int N, K, cur;
    while(cin >> N >> K){
        if(N >= K) { cout <<  (N - K) << endl; continue; }
        queue<int> q;
        q.push(N);
        vis[N] = 1; step[N] = 0;
        while(!q.empty()){
            cur = q.front(); q.pop();
            if(cur == K){
                cout << step[cur] << endl;
                break;
            }
            int next;
            for(int i = 1; i <= 3; i++){
                if(i == 1) next = cur * 2;
                else if(i == 2) next = cur - 1;
                else next = cur + 1;
                if(next >= 0 && next < maxn && !vis[next]){
                    step[next] = step[cur] + 1;
                    vis[next] = 1;
                    q.push(next);
                }
            }
        }
        memset(vis, 0, sizeof(vis));
    }
    
    return 0;
}