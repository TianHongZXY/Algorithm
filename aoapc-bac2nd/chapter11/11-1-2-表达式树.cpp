#include <cstdio>
const int maxn = 1e3;
int lch[maxn], rch[maxn];
char op[maxn];
int nc = 0;

int build_tree(char* s, int x, int y){
    int i, c1 = -1, c2 = -1, p = 0;
    int u;
    if(y - x == 1){ // 仅一个字符，建立单独结点
        u = ++nc;
        lch[u] = rch[u] = 0; op[u] = s[x];
        return u;
    }
    for(i = x; i < y; i++){
        switch (s[i]){
        case '(': p++; break;
        case ')': p--; break;
        case '+': case '-': if(!p) c1 = i; break;
        case '*': case '/': if(!p) c2 = i; break;
        }
    }
    if(c1 < 0) c1 = c2; // 括号外无加减号
    if(c1 < 0) build_tree(s, x + 1, y - 1); // 括号外也无乘除号，那么整个表达式被括号括起来了
    u = ++nc;
    lch[u] = build_tree(s, x, c1);
    rch[u] = build_tree(s, c1 + 1, y);
    op[u] = s[c1];
}

int main(){


    return 0;
}