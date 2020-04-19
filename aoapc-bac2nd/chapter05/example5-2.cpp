//
// Created by TianHongZXY on 2020/3/25.
//
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;
const int maxn = 30;
vector<int> pile[maxn];
int n;

void pile_onto(int p, int h, int p2){
    for(int i = h; i < pile[p].size();i++){
        pile[p2].push_back(pile[p][i]);
    }
    int size = pile[p].size();
    for(int i = h; i < size;i++){
        pile[p].pop_back();
    }
}

void clear_above(int p, int h){
    int size = pile[p].size();
    for(int i = size - 1; i >= h + 1; i--){
        int j = pile[p][i];
        pile[j].push_back(j);
        pile[p].pop_back();
    }
}

void find_block(int a, int& p, int& h){
    for(p = 0; p < n; p++){
        for(h = 0; h < pile[p].size(); h++){
            if(pile[p][h] == a) return;
        }
    }
}

void print(){
    for(int i = 0; i < n; i++){
        printf("%d:", i);
        for (auto p : pile[i]) printf(" %d", p);
        printf("\n");
    }
}

int main(){
    int a, b;
    cin >> n;
    string s1, s2;
    for(int i = 0; i < n; i++) pile[i].push_back(i);
//    while(scanf("%s %d %s %d", &s1, &a, &s2, &b) == 4 && s1 != "quit"){

    while(cin >> s1 && s1 != "quit"){
        cin >> a >> s2 >> b;
        int pa, pb, ha, hb;
        find_block(a, pa, ha);
        find_block(b, pb, hb);
        if(pa == pb || a == b) continue;
        if (s1 == "move") clear_above(pa, ha);
        if (s2 == "onto") clear_above(pb, hb);
        pile_onto(pa, ha, pb);
//        print();
//        printf("*******************\n");
    }
    print();
    return 0;
}