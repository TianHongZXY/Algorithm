#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
const int maxn = 1e6 + 5;
char s[10];
string pre = "";
string res[maxn];
int main(){
    int n;
    for(int i = 1; i <= maxn; i++){
        sprintf(s, "%d", i);
        string x(s);
        if(x > pre)
            pre = x;
        res[i] = pre;
        
    }
    while(scanf("%d", &n) == 1 && n){
        cout << res[n] << endl;
    }
    return 0;
}