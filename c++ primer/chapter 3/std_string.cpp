//
// Created by TianHongZXY on 2020/2/28.
//
#include <string>
#include <iostream>
using namespace std;

int main(){
    string s1;
    string s2 = s1;
    string s3 = "hiya";
    string s4(10, 'c');
    string s5(s4);
    string s6("hello");
    string s7 = string(10, 'c');
    cout << s3 << endl;
}