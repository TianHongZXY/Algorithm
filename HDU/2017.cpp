#include <cstdio>
#include <cstring>
#include <cctype>
const int maxn = 5000;
int main(){
    int n;
    char s[maxn];
    scanf("%d", &n);
    while(n--){
        scanf("%s", s);
        int cnt = 0, len = strlen(s);
        for(int i = 0; i < len; i++)
            if(!isalpha(s[i])) cnt++;
        printf("%d\n", cnt);
    }

    return 0;
}