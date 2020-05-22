#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <set>
using namespace std;
const int maxn = 35;
char wall[maxn][maxn];
int supported[26];
int main(){
    int T, R, C, kase = 0;
    set<char> polys;
    scanf("%d", &T);
    while(T--){
        memset(supported, 0, sizeof(supported));
        string for_print = "";
        polys.clear();
        scanf("%d%d", &R, &C);
        for(int i = R - 1; i >= 0; i--)
            scanf("%s", wall[i]);
        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++){
                char cur = wall[i][j];
                if(!polys.count(cur)) polys.insert(cur);
            }
        bool success = true;
        while(polys.size()){
            int erasehappen = 0;
            for(auto p: polys){
                bool hassupport = 1;
                for(int i = 0; i < R; i++){
                    for(int j = 0; j < C; j++){
                        if(wall[i][j] == p){
                            if(i == 0 || wall[i-1][j] == p || supported[wall[i-1][j] - 'A']) continue;
                            else { hassupport = 0; break;}
                        }
                    }
                    if(!hassupport) break;
                }
                if(hassupport){
                    for_print += p;
                    supported[p - 'A'] = 1;
                    polys.erase(p);
                    erasehappen = 1;
                    break;
                }
            }
            if(!erasehappen) { success = false; break; }
        }
        printf("Case #%d: ", ++kase);
        if(success)
            // for(auto s: for_print) printf("%c", s);
            cout << for_print;
        else printf("-1");
        printf("\n");
        
    }

    return 0;
}