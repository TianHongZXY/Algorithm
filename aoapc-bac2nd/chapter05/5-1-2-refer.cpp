//
// Created by TianHongZXY on 2020/3/25.
//
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100 + 10;
int M[maxn];

void swap2(int& a, int& b){
    int t = a;
    a = b;
    b = t;
}

int main(){
    int a = 10, b = 20;
    cout << min(a, b) << endl;
    swap2(a, b);
    cout << a << " " << b << endl;

    return 0;
}