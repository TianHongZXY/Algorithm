#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <set>
using namespace std;
#define mod (10007)
string s[110];
set<string> st;

int fac(int n){
    int ans = 1;
    for(int i = 1; i <= n; i++)
        ans *= i;
    return ans;
}

int main(){
    int n, m;
    int ans = 1;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        ans = (ans * 26) % mod;
    }
    for(int i = 0; i < n; i++){
        cin >> s[i];
        st.insert(s[i]);
    }
    int del = m - 1;

    for(int i = 0; i < m - 2; i++){
        del = (del * 26) % mod;
    }
    del = (del * st.size()) % mod;
    printf("%d", (ans - del) % mod);
    return 0;
}
