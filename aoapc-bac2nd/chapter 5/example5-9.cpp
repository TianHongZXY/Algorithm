//
// Created by TianHongZXY on 2020/3/28.
//
#include<bits/stdc++.h>
#include <cassert>
using namespace std;
const int maxm = 10 + 2;;
const int maxn = 10000 + 10;
int colstr2id[maxn][maxm];
map<string, int> str2id;
vector<string> id2str;
pair<int, int> pr;
map<pair<int, int>, int> pr2id;

int ID(string s){
    if(str2id.count(s)) return str2id[s];
    id2str.push_back(s);
    return str2id[s] = id2str.size() - 1;
}

int main(){
    int rows, cols;
    string row;
    while(scanf("%d%d", &rows, &cols) == 2) {
        getchar();
        str2id.clear();
        id2str.clear();
        for (int i = 1; i <= rows; i++) {
            getline(cin, row);
            stringstream ss(row);
            string element;
            int col = 1;
            while (getline(ss, element, ',')) {
                colstr2id[i][col++] = ID(element);
            }
        }
        bool isPNF = true;
        for(int i = 1; i <= cols - 1; i++){
            if (!isPNF) break;
            for(int j = i + 1; j <= cols; j++){
                if (!isPNF) break;
                pr2id.clear();
                for(int r = 1; r <= rows; r++){
                    pr = make_pair(colstr2id[r][i], colstr2id[r][j]);
                    if(pr2id.count(pr)) {cout << "NO\n" << pr2id[pr] << " " << r << '\n'
                                              << i << " " << j << endl; isPNF=false; break;}
                    else pr2id[pr] = r;
                }
            }
        }
        if(isPNF) cout << "YES" << endl;
        memset(colstr2id, -1, maxn * maxm);
    }
    return 0;
}
