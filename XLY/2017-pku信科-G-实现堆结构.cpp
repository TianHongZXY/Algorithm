#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int t = 1, n, op, num;
    // scanf("%d", &t);
    while(t--){
        priority_queue<int, vector<int>, greater<int> > pq;
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &op);
            if(op == 1){
                scanf("%d", &num);
                pq.push(num);
            }
            else{
                if(pq.empty()) continue;
                int x = pq.top();
                pq.pop();
                printf("%d\n", x);
            }
        }
    }

    return 0;
}