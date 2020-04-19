//
// Created by TianHongZXY on 2020/4/1.
//
#include <bits/stdc++.h>
using namespace std;
set<string> dict;
int main(){
    string w;
    while(cin >> w){
        dict.insert(w);
    }
    for(string t: dict){
        for(int i = 1; i < t.length(); i++){
            string l = t.substr(0, i);
            string r = t.substr(i);
            if(dict.count(l) && dict.count(r)){
                cout << t << endl;
                break;
            }
        }
    }

    return 0;
}
