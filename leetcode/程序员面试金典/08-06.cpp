/* ====================================================
#   Copyright (C) 2021  All rights reserved.
#
#   Author        : Xinyu Zhu
#   Email         : zhuxy21@mails.tsinghua.edu.cn
#   File Name     : 08-06.cpp
#   Last Modified : 2021-10-27 21:01
#   Describe      : 
#
# ====================================================*/

#include <iostream>
#include <vector>
using namespace std;

// https://leetcode-cn.com/problems/hanota-lcci/solution/tu-jie-yi-nuo-ta-de-gu-shi-ju-shuo-dang-64ge-pan-z/

void step(int n, vector<int>& A, vector<int>& B, vector<int>& C) {
    // 移动A号塔上最小的那片到C塔
    if(n == 0) {
        int a = A.back();
        A.pop_back();
        C.push_back(a);
        return;
    }
    else {
        // 把A号塔上的 0 ~ n-1 号利用C号塔作为中间塔，移到B塔
        step(n - 1, A, C, B);
        // 把A号塔上的 n 号（即最大的那片）移到C塔
        int a = A.back();
        A.pop_back();
        C.push_back(a);
        // 把B号塔上的 0 ~ n-1 号利用A号塔作为中间塔，移到C塔
        step(n - 1, B, A, C);
    }
}

void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
    step(A.size() - 1, A, B, C);
}

int main() {
    vector<int> A = {1, 0};
    vector<int> B;
    vector<int> C;
    hanota(A, B, C);

    for(int x : C) {
        cout << x << " ";
    }
}
