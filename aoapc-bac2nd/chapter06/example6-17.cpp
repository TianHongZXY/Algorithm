#include <bits/stdc++.h>
using namespace std;
const int maxn = 200 + 5;
char buf[maxn][maxn];
set<char> unnode;
void dfs(int r, int c){
    int lc = c, rc = c; // lc~rc为‘-’的范围
    for(;lc >= 0; lc--)
        if(buf[r+2][lc] == '-') continue; else break;
    for(;rc < maxn; rc++)
        if(buf[r+2][rc] == '-') continue; else break;
    for(int i = lc + 1; i < rc; i++){
        if(!unnode.count(buf[r+3][i])){ // 非unnode中的字符
            cout << buf[r+3][i]; 
            if(buf[r+4][i] != '|') cout << "()"; // 无子树
            else{
                cout << '('; dfs(r+3, i);cout << ')'; // 有子树 继续递归
            }
        }
    }
}

int main(){
    int T;
    scanf("%d", &T);
    getchar(); // 去掉scanf遗留的'\n'
    unnode.insert('\0'); unnode.insert('-'); unnode.insert('|'); unnode.insert(' '); unnode.insert('#'); // 非node字符
    while(T--){
        memset(buf, 0, sizeof(buf));
        int r = 0;
        while(cin.getline(buf[r], 201, '\n'))
            if(buf[r][0]=='#') break; else r++;
        cout << '('; // 最外层的括号
        for(int j = 0; j < maxn; j++){ // 找到第一行的根节点，然后开始往下dfs
            if(!unnode.count(buf[0][j])){
                cout << buf[0][j];
                if(buf[1][j] == '|'){
                    cout << '('; dfs(0, j); cout << ')';
                } else cout << "()";
            }
        }
        cout << ')' << endl;
    }
    return 0;
}