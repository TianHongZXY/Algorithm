#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    char s[10];
    while(scanf("%s", s) == 1 && s != ""){
        for(int i = 0; i < 3; i++)
            for(int j = i + 1; j < 3; j++){
                if(s[j] < s[i]) swap(s[j], s[i]);
            }
        for(int i = 0; i < 3; i++) printf("%c%c", s[i], i == 2 ? '\n' : ' ');
    }
    return 0;
}