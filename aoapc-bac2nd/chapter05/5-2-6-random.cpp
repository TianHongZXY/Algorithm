//
// Created by TianHongZXY on 2020/3/27.
//
#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

void fill_random_int(vector<int>& v, int cnt){
    v.clear();
    for(int i = 0; i < cnt; i++)
        v.push_back(rand());
}

void test_sort(vector<int>& v){
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size() - 1; i++)
        assert(v[i] <= v[i+1]);
}

int main(){
    srand(time(NULL));
    vector<int> v;
    fill_random_int(v, 100);
    test_sort(v);

    return 0;
}