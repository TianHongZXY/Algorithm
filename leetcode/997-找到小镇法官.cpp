//
// Created by TianHongZXY on 2020/4/18.
//
#include <vector>
#include <iostream>
using namespace std;


int trustcnt[1001] = {0};
int betrustedcnt[1001] = {0};
int findJudge(int N, vector<vector<int>>& trust) {
    for(int i = 0; i < trust.size(); i++){
        trustcnt[trust[i][0]]++;
        betrustedcnt[trust[i][1]]++;
    }
    int found = -1;
    for(int i = 1; i <= N; i++){
        if(trustcnt[i] == 0 && betrustedcnt[i] == N-1)
            found = i;
    }
    return found;
}

int main(){
    vector<vector<int> > trust;
    vector<int> i1 = {1, 3};
    vector<int> i2 = {1, 4};
    vector<int> i3 = {2, 3};
    vector<int> i4 = {2, 4};
    vector<int> i5 = {4, 3};
    trust.push_back(i1);
    trust.push_back(i2);
    trust.push_back(i3);
    trust.push_back(i4);
    trust.push_back(i5);
    cout << findJudge(4, trust);
}