#include <cstdio>
#include <cstring>
#include <cctype>
const int maxn = 1000 + 10;
char s[maxn];
int main(){
    scanf("%s", s);
    int n = strlen(s);
    for(int i = 0; i < n; i++){
        if(isupper(s[i]))
            s[i] = tolower(s[i]);
    }
    s[n] = '#'; s[n+1] = '\0';
    int cnt = 1;
    for(int i = 0; i < n; i++){
        if(s[i] == s[i + 1]){
            cnt++;
        }
        else{
            printf("(%c,%d)",s[i], cnt);
            cnt = 1;
        }
    }

    return 0;
}