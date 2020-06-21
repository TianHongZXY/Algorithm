#include <cstdio>
#include <queue>
#include <string>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct path{
    int cur, step;
    // string way;
    vector<char> way;
};

void print(path x){
    printf("%d\n", x.step);
    for(int i = 0; i < x.way.size(); i++)
        printf("%c", x.way[i]);
    return;
}

int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) == 2 && n && m){
        queue<path> Q;
        set<int> st;
        path s; s.cur = n; s.step = 0;
        st.insert(s.cur);
        Q.push(s);
        while(!Q.empty()){
            path x = Q.front(); Q.pop();
            if(x.cur == m){
                print(x);
                break;
            }
            path xh = x, xo = x;
            xh.cur *= 3; xh.step++; xh.way.push_back('H');
            xo.cur /= 2; xo.step++; xo.way.push_back('O');
            if(xh.cur == m){
                print(xh); break;
            }
            if(xo.cur == m){
                print(xo); break;
            }
            if(!st.count(xh.cur)) Q.push(xh);
            if(!st.count(xo.cur)) Q.push(xo);
        }
    }
    return 0;
}