#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
// using namespace std;
struct city{
    int neighbor[3];
    int path[25];
};
city citys[30];
int m, count, usemneighs, vis[25];
std::set<int> mneighs;

void dfs(int begin, int cur){
    citys[m].path[cur] = begin;
    if(cur == 20){
        int ok = 0;
        for(int i = 0; i < 3; i++){
            if(citys[begin].neighbor[i] == m){
                ok = 1; break;
            }
        }
        if(!ok) return;
        printf("%d:  ", ++count);
        for(int i = 1; i <= 20; i++)
            printf("%d%c", citys[m].path[i], ' ');
        printf("%d\n", m);
        return;
    }
    if(usemneighs == 3) return;
    for(int i = 0; i < 3; i++){
        if(!vis[citys[begin].neighbor[i]]){
            vis[citys[begin].neighbor[i]] = 1;
            if(mneighs.count(citys[begin].neighbor[i])) usemneighs++;
            dfs(citys[begin].neighbor[i], cur + 1);
            usemneighs--;
            vis[citys[begin].neighbor[i]] = 0;
        }
    }
}
int main(){
    for(int i = 1; i <= 20; i++){
        scanf("%d %d %d", &citys[i].neighbor[0], &citys[i].neighbor[1], &citys[i].neighbor[2]);
    }
    while(scanf("%d", &m) == 1 && m){
        count = 0; usemneighs = 0;
        for(int i = 0; i < 3; i++) mneighs.insert(citys[m].neighbor[i]);
        vis[m] = 1;
        dfs(m, 1);
        mneighs.clear();
        memset(vis, 0, sizeof(vis));
    }

    return 0;
}