//
// Created by TianHongZXY on 2020/4/15.
//
#include <bits/stdc++.h>
using namespace std;

void trans() { // 一位16进制字符[0,f]转为4位的二进制字符串
    char c[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    for (int i = 0; i < 16; i ++) {
        bitset<4> bt(i);
        cout << bt.to_string() << " ";
    }
}

int main(){
    trans();
}