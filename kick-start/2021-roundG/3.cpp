/* ====================================================
#   Copyright (C) 2021  All rights reserved.
#
#   Author        : Xinyu Zhu
#   Email         : zhuxy21@mails.tsinghua.edu.cn
#   File Name     : 3.cpp
#   Last Modified : 2021-10-16 21:34
#   Describe      : 
#
# ====================================================*/

#include <iostream>
#include <cstring>
using namespace std;
int tree[5000 + 10];
int main () {
    int T, N, K;
    cin >> T;
    for(int k = 1; k <= T; k++) {
        cin >> N >> K;
        memset(tree, 0, sizeof(int) * 5010);
        for(int i = 1; i <= N; i++)
            cin >> tree[i];
        
    }
}
