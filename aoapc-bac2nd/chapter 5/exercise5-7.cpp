//
// Created by TianHongZXY on 2020/4/2.
//
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;

struct Job{
    int pos, pri;
}job;

int main(){
    int t, n, x, a, f;
    scanf("%d", &t);
    while(t--){
        map<int, int> mp;
        queue<Job> q;
        scanf("%d%d", &n, &x);
        for(int i = 0; i < n; i++) {
            scanf("%d", &job.pri);
            job.pos = i;
            q.push(job);
            mp[job.pri]++;
        }
        int time = 0;
        while(!q.empty()){
            if(q.front().pri < mp.rbegin()->first){q.push(q.front()); q.pop();}
            else if(q.front().pos == x){time++; break;}
            else{
                if (mp[q.front().pri] == 1) mp.erase(q.front().pri);
                else mp[q.front().pri]--;
                time++;
                q.pop();
            }
        }
        cout << time << endl;
    }
    return 0;
}