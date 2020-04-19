//
// Created by TianHongZXY on 2020/3/28.
//
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 100 + 5;
const int maxcol = 60;
string filenames[maxn];

void print(const string& s, int len, char extra){
    cout << s;
    for(int i = 0; i < len - s.length(); i++)
        cout << extra;
}

int main(){
    int n;
    while(cin >> n){
        int M = 0;
        for(int i = 0; i < n; i++){
            cin >> filenames[i];
            M = max(M, (int)filenames[i].length());
        }
        int cols = (maxcol - M) / (M + 2) + 1, rows = (n - 1) / cols + 1;
        print("", 60, '-');
        cout << '\n';
        sort(filenames, filenames+n);
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                int idx = c * rows + r;
                if (idx < n) print(filenames[idx], c == cols-1 ? M : M + 2, ' ');
            }
            cout << '\n';
        }
    }
    return 0;
}

// 别人的解法，思路更好理解
/*
#include<bits/stdc++.h>
using namespace std;
int n;
string s, format;
int main() {
    while (cin >>n) {
        int maxlen=-1, len, colNum=1, rowNum;
        set<string> _set;
        for (int i = 0; i < n; i ++) {
            cin >>s; _set.insert(s);
            maxlen = max(maxlen, (int)s.size()); // 最长长度
        }
        while ((maxlen+2)*colNum-2 <= 60) colNum++; // 列数
        colNum --; rowNum = (int)ceil((float)n / colNum); // 行数
        vector<string> fnames;
        fnames.insert(fnames.begin(), _set.begin(), _set.end()); // set转为vector
        printf("%s\n", string(60,'-').c_str()); // 60个-
        for (int i = 0; i < rowNum; i ++) { // 遍历输出
            for (int j = 0; j < colNum && j*rowNum+i < n; j ++) {
                len = (j == colNum-1) ? maxlen : maxlen+2; // 最后一列对其宽度为maxlen
                format = "%-"+to_string(len)+"s"; // 输出格式
                printf(format.c_str(), fnames[j*rowNum+i].c_str());
            }
            puts("");
        }
    }
    return 0;
}
 */