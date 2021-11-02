/* ====================================================
#   Copyright (C) 2021  All rights reserved.
#
#   Author        : Xinyu Zhu
#   Email         : zhuxy21@mails.tsinghua.edu.cn
#   File Name     : 08-07.cpp
#   Last Modified : 2021-11-01 17:24
#   Describe      : 
#
# ====================================================*/

#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

vector<string> step(char a, string b, int n, vector<string>& res) {
    vector<string> cur, prev;
    if(b.length() == 1) {
        cur.push_back(a + b); cur.push_back(b + a);
    }
    else if (b.length() > 2){
        for(int i = 0; i < b.length(); i++) {
            prev = step(b[i], b.substr(0, i) + b.substr(i + 1, b.length()), n - 1, res);
            for(auto s : prev)
                cur.push_back(a + s);
        }
    }
    else {
        prev = step(b[0], b.substr(1, b.length()), n - 1, res);
        for(auto s : prev)
            cur.push_back(a + s);
    }
    if(n == res[0].length())
        res.insert(res.end(), cur.begin(), cur.end());
    return cur;
}

vector<string> permutation(string S) {
    vector<string> res;
    res.push_back(S);
    if(S.length() == 1)
        res.push_back(S);
    else if(S.length() == 2) {
        res.push_back(S);
        res.push_back(S.substr(1, S.length()) + S[0]);
    }
    else {
        for(int i = 0; i < S.length(); i++)
            step(S[i], S.substr(0, i) + S.substr(i + 1,S.length()), S.length(), res);
    }
    res.erase(res.begin());
    return res;
}

vector<string> permutation1(string S) {
    sort(S.begin(), S.end());
    vector<string> res;
    res.push_back(S);
    while(next_permutation(S.begin(), S.end())) {
        res.push_back(S);
    }

    return res;
}

void backtrack2(string S, string path, vector<string>& res) {
    if(S.length() == 0) {
        res.push_back(path);
        return;
    }
    for(int i = 0; i < S.length(); i++) {
        char cur = S[i];
        backtrack(S.substr(0, i) + S.substr(i + 1, S.length()), path + cur, res);
    }
}

vector<string> permutation2(string S) {
    vector<string> res;
    if(S.length() == 0) return res;
    string path = "";
    backtrack2(S, path, res);
    return res;
}


void backtrack3(string S, char* sb, int* visited, vector<string>& res) {
    if(strlen(sb) == S.length()) {
        res.push_back(string(sb));
        return;
    }
    for(int i = 0; i < S.length(); i++) {
        if(visited[i]) continue;
        visited[i] = 1;
        sb[strlen(sb)] = S[i];
        backtrack3(S, sb, visited, res);
        sb[strlen(sb) - 1] = '\0';
        visited[i] = 0;
    }
    return;
}

vector<string> permutation3(string S) {
    vector<string> res;
    char sb[S.length() + 1];
    int visited[S.length()];
    memset(sb, 0, sizeof(char) * (S.length() + 1));
    memset(visited, 0, sizeof(int) * S.length());
    backtrack3(S, sb, visited, res);
    return res;
}

int main() {
    string S = "qwe";
    // cout << S[0] << endl;
    // cout << typeid(S[0]).name() << endl;
    vector<string> res = permutation2(S);
    for(auto s : res)
        cout << s << endl;
    cout << res.size() << endl;
}
