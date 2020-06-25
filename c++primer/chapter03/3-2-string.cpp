//
// Created by TianHongZXY on 2020/2/28.
//
#include <string>
#include <iostream>
#include <cctype>
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
    cout << s8 + "123" + "456" << endl;
    cout << isalnum('5') << endl;
    cout << islower('A') << endl;

    for (auto c : phrase)
        cout << c << endl;
    string s9("Hello, World!!!");
    decltype(s9.size()) punct_cnt = 0;
//    string::size_type punct_cnt = 0; // equal to the line above
    for (char c : s9)
        if (ispunct(c)) punct_cnt++;
    cout << punct_cnt << " punctuation characters in " + s9 << endl;
    // use reference to change string
    for (auto &c : s9)
        c = toupper(c);
    cout << s9 << endl;
    s9 = "Hello, World!!!";
    if (!s9.empty()) cout << s9[0] << endl;
    for (decltype(s9.size()) index = 0; index != s9.size() && !isspace(s9[index]); ++index)
        s9[index] = toupper(s9[index]);
    cout << s9 << endl;


    return 0;
}