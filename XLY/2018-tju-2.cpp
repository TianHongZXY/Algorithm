// 题目链接 https://zhuanlan.zhihu.com/p/107194264?utm_source=qq
#include <cstdio>
#include <cstring>
#include <cctype>
const int maxn = 1e5;
char s[maxn];

int main(){
    int T, len;
    scanf("%d", &T);
    while(T--){
        scanf("%s", s);
        len = strlen(s);
        for(int i = 0; i < len; i++){
            if(isupper(s[i]))
                s[i] = tolower(s[i]);
            else if(islower(s[i]))
                s[i] = (s[i] == 'z' ? 'a' : (s[i] + 1));
        }
        printf("%s\n", s);
    }
    return 0;
}