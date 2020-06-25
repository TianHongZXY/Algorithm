//
// Created by TianHongZXY on 2020/4/14.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    vector<int> v1(10, 3);
    auto b = v1.begin(), e = v1.end();
    cout << *b << " " << *(b+1) << " " << endl;
    cout << (b == b+1) << endl;
    cout << (b+1 == b+1) << endl;

    string s("some string");
    for(auto it = s.begin(); it != s.end(); it++){
        *it = toupper(*it);
    }
    cout << s << endl;

    vector<int>::iterator vit1; // 可读可写
    vector<int>::const_iterator vit2; // 只读，不可写
    string::iterator vs1;
    string::const_iterator vs2; //只读，不可写
//    const vector<int>::iterator vit3;  // const vector对象应使用const_iterator
    const vector<int>::const_iterator vit4;
    auto vit5 = v1.cbegin(); // cbegin(), cend()返回const_iterator
//    cout << typeid(vit4).name() << endl;

    vector<string> v2(1, "i love cj");
    auto it2 = v2.cbegin();
    // (*it).empty()先解引用再执行所指字符串的empty()函数，it2->empty()将解引用和成员访问两个操作结合在一起
    cout << (*it2).empty() << " " << it2->empty() << endl;
    for(auto it = v2.cbegin(); it != v2.cend() && !it->empty(); it++)
        cout << *it << endl;
    // 对vector进行push_back会导致该对象的迭代器失效
    // exercise3-23
    vector<int> e323{1,2,3,4,5,6,7,8,9,10};
    for(auto it = e323.begin(); it != e323.end(); it++)
        *it = (*it) * 2;
    for(auto x: e323) cout << x << " ";


    return 0;
}