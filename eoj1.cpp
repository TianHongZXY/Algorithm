#include <cstdio> 
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
const int maxn = 1e6 + 10;
char s[maxn];
using namespace std;
int main(){
    int T;
    string a;
    vector<int> b;
    scanf("%d", &T);
    while(T--){
        scanf("%s", s);
        int len = strlen(s);
        int possible = 1, happy = 1;
        for(int i = 0; i < len; i++){
            if(s[i] == 'b'){
                if(i == 0 || (i - 1 >= 0 && s[i - 1] == 'b')){
                    possible = 0; break;
                }
                if(i - 2 >= 0 && s[i - 2] == 'a'){
                    happy = 0;
                }
            }
        }
        if(possible){
            if(happy) printf("Happy Fang\n");
            else printf("Sad Fang\n");
        }
        else printf("Dead Fang\n");
    }
    return 0;
}
