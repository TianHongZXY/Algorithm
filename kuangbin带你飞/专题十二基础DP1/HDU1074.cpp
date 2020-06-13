#include <cstdio>
#include <string>
#include <iostream>
#include <stack>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 20;

struct subject{
    string name;
    int cost, ddl;
}sj[maxn];
struct states{
    int prev, fini, time, lost; // 上一状态，该次写的哪门课，到该状态耗时，已损失的分数
}dp[1<<15];

int main(){
    int T, n;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            cin >> sj[i].name >> sj[i].ddl >> sj[i].cost;
        int end = 1 << n;
        for(int i = 1; i < end; i++){ // 求到达状态i时，丢掉的最少分
            dp[i].lost = INF;
            for(int j = n - 1; j >= 0; j--){
                int cursj = 1 << j;
                if(i & cursj){
                    int prevdp = i - cursj;
                    int chosejlost = dp[prevdp].time + sj[j].cost - sj[j].ddl;
                    chosejlost = max(chosejlost, 0);
                    // 可以这样想，假如当前i就是最后一个状态，当然是希望最后一门课 即字典序最大的课j刚好被放在这个地方，
                    // 又因为遍历过程中j是在减小的，所以只有当lost严格减小时才更新dp[i].fini为j
                    if(dp[prevdp].lost + chosejlost < dp[i].lost){ 
                        dp[i].lost = dp[prevdp].lost + chosejlost;
                        dp[i].prev = prevdp;
                        dp[i].fini = j;
                        dp[i].time = dp[prevdp].time + sj[j].cost;
                    }
                }
            }
        }
        cout << dp[end - 1].lost << endl;
        stack<int> stk;
        int x = end - 1;
        while(dp[x].time){
            stk.push(dp[x].fini);
            x = dp[x].prev;
        }
        while(!stk.empty()){
            int subj = stk.top(); stk.pop();
            cout << sj[subj].name << endl;
        }
    }

    return 0;
}