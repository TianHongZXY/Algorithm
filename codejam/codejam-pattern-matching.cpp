//
// Created by TianHongZXY on 2020/4/11.
//
#include <bits/stdc++.h>
using namespace std;

bool substr_(string l, string s){
    int len = s.length();
    int n = l.length();
    for(int i = 0; i <= n - len; i++){
        string sb = l.substr(i, len);
        if(sb.compare(s) == 0) return true;
    }
    return false;
}

int main(){
    int T, n, kase=0;
    string p;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        getchar();
        bool possible = true;
        int len = 0;
        string candi;
        for(int i = 0; i < n; i++){
            getline(cin, p);
            p = p.substr(1);
            if(p.length() > len) {
                if (substr_(p, candi)) {
                    candi = p;
                    len = p.length();
                }
                else {
                    possible = false;
                    break;
                }
            }
            else {
                if (!substr_(candi, p)) {
                    possible = false;
                    break;
                }
            }
        }
        printf("Case #%d: ", ++kase);
        if(possible) cout << candi << endl;
        else cout << "*" << endl;
    }
    return 0;
}
