//
// Created by TianHongZXY on 2020/3/27.
//
#include <queue>
#include <cstdio>
#include <map>
using namespace std;
const int maxt = 1000 + 10;

int main(){
    int t, kase = 0;
    while(scanf("%d", &t) == 1 && t){
        printf("Scenario #%d\n", ++kase);
        queue<int> lq;
        map<int, int> memberid2teamid;
        queue<int> teamid2queue[maxt];
        for(int j = 0; j < t; j++) {
            int num_member, memberid;
            scanf("%d", &num_member);
            while(num_member--){
                scanf("%d", &memberid);
                memberid2teamid[memberid] = j;
            }
        }
        while(1) {
            getchar();
            char command[10];
            scanf("%s", command);
            if (command[0] == 'E') {
                int mid;
                scanf("%d", &mid);
                int tid = memberid2teamid[mid];
                if (teamid2queue[tid].empty()) lq.push(tid);
                teamid2queue[tid].push(mid);
            } else if (command[0] == 'D') {
                int tid = lq.front();
                printf("%d\n", teamid2queue[tid].front());
                teamid2queue[tid].pop();
                if (teamid2queue[tid].empty())
                    lq.pop();
            } else
                break;
        }
        printf("\n");
    }
}