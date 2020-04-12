//
// Created by TianHongZXY on 2020/4/11.
//
#include <stack>
#include <vector>
using namespace std;

vector<int> dailyTemperatures(vector<int>& T) {
    vector<int> res(T.size());
    stack<int> temp;
    for(int i = 0; i < T.size(); i++){
        if(!temp.empty()){
            while(!temp.empty() && T[i] > T[temp.top()]){
                res[temp.top()] = i - temp.top();
                temp.pop();
            }
            temp.push(i);
        }
        else temp.push(i);
    }
    return res;
}