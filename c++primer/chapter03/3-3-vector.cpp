//
// Created by TianHongZXY on 2020/2/28.
//
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    vector<int> ivec;
    vector<vector<string> > file;
    vector<int> v1;
    vector<int> v2(v1); // equal to vector<int> v2 = v1;
    vector<double> v3(10, 3.14);
    vector<int> v4(10);
    vector<int> v5{1,2,3,4,5};
    vector<int> v6 = {1,2,3,4,5};
    vector<string> v7 = {"123", "456"};
    cout << v7[1] << endl;
    vector<string> v8{"a", "an", "the"};
//    vector<string> v9("a", "an", "the"); // wrong!
    vector<string> v9(10, "hello world");
    cout << v9[9] << endl;
    // () or {} initialize ?
    vector<int> v10(10); // 10 elements, all are 0
    vector<int> v11{10}; // 1 element and it's 10

    vector<int> v12(10, 1); // 10 elements, all are 1
    vector<int> v13{10, 1}; // 2 elements: 10 and 1

    vector<string> v14{"hi"}; // 1 element: "hi"
//    vector<string> v15("hi"); // wrong
    vector<string> v16{10}; // 10 elements, all default initialized
    vector<string> v17{10, "hi"}; // 10 elements，all initialized with "hi"

    vector<int> v18;
    for (int i = 0; i != 100; i++)
        v18.push_back(i);

    string word;
    vector<string> text;
    while (cin >> word) {
        if (word == "q") break;
        text.push_back(word);
    }
    for(auto &s: text){
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        cout << s << " ";
        printf("%s ", s.c_str());
    }

    //    vector::size_type  n = text.size(); 错误写法
    vector<string>::size_type n = text.size();
    int n1 = text.size();
    decltype(text.size()) n2 = text.size();
    cout << n << " " << n1 << " " << n2 << endl;

    vector<unsigned> score(11, 0);
    unsigned grade;
//    while(cin >> grade){
//        if(grade <= 100)
//            ++score[grade/10];
//        else break;
//    }
//  exercise 3-19
    vector<int> e319{42,42,42,42,42,42,42,42,42,42};
    vector<int> e319_(10, 42);  // i think this is the best
    vector<int> e319__;
    for(int i = 0; i < 10; i++) e319__.push_back(42);



    return 0;
}