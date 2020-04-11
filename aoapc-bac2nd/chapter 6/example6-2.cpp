//
// Created by TianHongZXY on 2020/4/6.
//
#include <stack>
#include <cstdio>
using namespace std;
const int maxn = 1000 + 10;

int main(){
    int n;
    int target[maxn];
    while(scanf("%d", &n) == 1 && n){
        while(true) {
            scanf("%d", &target[1]);
            if (target[1] == 0) {
                printf("\n");
                break;
            }
            stack<int> s;
            // A就是列车开始的顺序，不断被压入栈(进入C车站)或开到B车站去
            int A = 1, B = 1;
            for (int i = 2; i <= n; i++)
                scanf("%d", &target[i]);
            int ok = 1;
            while (B <= n) {
                // 当前target[B]与A相等，车厢从A开到B，A和B都加一
                if (A == target[B]) {
                    A++;
                    B++;
                }
                // 当前的target[B]与C车站栈顶相等 B加一
                else if (!s.empty() && s.top() == target[B]) {
                    s.pop();
                    B++;
                }
                // 如果A站还有车，把车厢开到C站暂驻
                else if (A <= n) s.push(A++);
                // 当A站无车，且C站的栈顶车不等于target[B]，则No
                else {
                    ok = 0;
                    break;
                }
            }
            printf("%s\n", ok ? "Yes" : "No");
        }
    }

    return 0;
}
