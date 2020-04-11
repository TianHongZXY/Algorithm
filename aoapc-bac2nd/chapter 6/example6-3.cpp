//
// Created by TianHongZXY on 2020/4/7.
//
#include <stack>
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int n, r, c;
char mat;
int matrices[26][2];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        getchar();
        scanf("%c %d %d", &mat, &r, &c);
        matrices[mat-'A'][0] = r;
        matrices[mat-'A'][1] = c;
    }
    getchar();
    string line;
    stack<pair<int, int> > s;
    while(getline(cin, line) && line != "") {
        int res = 0;
        int len = line.length();
        bool error = false;
        for(int i = 0; i < len; i++){
            if (isalpha(line[i])){
                s.push(make_pair(matrices[line[i]-'A'][0], matrices[line[i]-'A'][1]));
            }
            else if(line[i] == ')'){ // 右括号，弹出两个矩阵 相乘后再把结果压回栈
                pair<int, int> right = s.top(); s.pop();
                pair<int, int> left = s.top(); s.pop();
                if (left.second == right.first){
                    res += left.first * left.second * right.second;
                    s.push(make_pair(left.first, right.second));
                }
                else { error = true; break;}
            }
            else continue; // 忽略左圆括号
        }
        if(error) printf("error\n"); else printf("%d\n", res);
    }
    return 0;
}