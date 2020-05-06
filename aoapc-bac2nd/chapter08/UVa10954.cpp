#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 5000 + 5;
int main(){
    int n, x, y;
    while(scanf("%d", &n) == 1 && n){
        priority_queue<int, vector<int>, greater<int> > pq;
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            pq.push(x);
        }
        int ans = 0;
        while(pq.size() > 1){
            x = pq.top(); pq.pop();
            y = pq.top(); pq.pop();
            pq.push(x + y);
            ans += (x + y);
        }
        printf("%d\n", ans);
    }

    return 0;
}