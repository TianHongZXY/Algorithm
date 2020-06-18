//
// Created by TianHongZXY on 2020/4/15.
//
#include <bits/stdc++.h>
using namespace std;

int main(){
    string w;
    stack<string> stk;
    while(cin >> w && w != ""){
        stk.push(w);
    }
    bool first = true;
    while(!stk.empty()){
        w = stk.top(); stk.pop();
        if(first) first = false;
        else cout << " ";
        cout << w;
    }
}