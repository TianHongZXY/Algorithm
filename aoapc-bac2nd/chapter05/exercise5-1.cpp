//
// Created by TianHongZXY on 2020/3/31.
//

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
int length[maxn];
vector<string> codes[maxn];

int main(){
    int l;
    int num_line = 0;
    string line;
    string word;
    while(getline(cin, line)){
        stringstream ss(line);
        l = 0;
        while(ss >> word) {
            length[l] = max((int)word.length(), length[l]); // 记录整个输入中第l个单词的最大长度
            l++;
            codes[num_line].push_back(word); // 添加第row行第l个单词
        }
        num_line++;
    }

    for(int i = 0; i < num_line; i++){
        int num_word = codes[i].size();
        for (int j = 0; j < num_word - 1; j++){
            int num_space = length[j] - codes[i][j].length(); // 打印该单词后还需要补齐的空格长度
            string space(num_space + 1, ' '); // +1 是分隔空格
            cout << codes[i][j] << space; // 第一个单词前没有空格
        }
        cout << codes[i][num_word - 1] << endl; // 每行最后一个单词后面不需要再根据最大单词长度打印空格了
    }
    return 0;
}