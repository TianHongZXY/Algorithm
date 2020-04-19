//
// Created by TianHongZXY on 2020/4/15.
//
#include <bits/stdc++.h>
using namespace std;

int flip(string& x, int i){
    int is1 = x[i] - '0';
    if(is1) x[i] = '0';
    else x[i] = '1';
}
void search(string & x, int& cnt, string tgt){
    int n = x.length();
    for(int i = 1; i < n; i++){
        if(x[i-1] != tgt[i-1]){
            cnt++;
            flip(x, i-1);
            flip(x, i);
            if(i+1 < n)
                flip(x, i+1);
        }
    }
}

int main(){
    int cnt = 0;
    string src, tgt;
    cin >> src >> tgt;
    string temp = src;
    int n = src.length();
    int case1 = 1, case2 = 0;
    flip(temp, 0); flip(temp, 1); // case1情况，翻转第一个
    search(src, case2, tgt);
    search(temp, case1, tgt);
    bool ok = false;
    int ans = 100;
    if(temp == tgt){
        ok = true;
        ans = min(ans, case1);
    }
    if(src == tgt){
        ok = true;
        ans = min(ans, case2);
    }
    if(ok) cout << ans << endl;
    else cout << "impossible" << endl;

    return 0;
}