//
// Created by TianHongZXY on 2020/3/25.
//
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    string line;
    getline(cin, line);
    int sum = 0, x;
    stringstream ss (line);
    while(ss >> x) sum += x;
    cout << sum << endl;
}