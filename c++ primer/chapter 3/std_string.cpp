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
    cout << (s7 > s6) << endl;

    string word;
//    while (cin >> word)
//        cout << word << endl;

    string line;
//    while (getline(cin, line))
//        if (!line.empty())
//            cout << line.size() << ' ' << line << endl;
//        else
//            break;
    string L("zzzzzz");
    string::size_type len = L.size();
    cout << len << endl;
    auto leng = L.size();
    int Length = L.size();
//  len's type is size_type and size() returns an unsigned int,
//  so almost every negative int is bigger than it, we shouldn't compare it with plain int.
    cout << (len < -1) << endl;

    string str = "Hello";
    string phrase = "Hello World";
    string slang = "Hiya";
    cout << (str < phrase) << ' ' << (phrase < slang) << endl;

    cout << (str + slang) << endl;
    string s8 = str + phrase;
    return 0;
}