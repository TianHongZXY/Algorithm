// 题目链接 https://zhuanlan.zhihu.com/p/107194264?utm_source=qq
#include <cstdio>
#include <cmath>
#include <algorithm>
const int maxn = 1e5;
int len[maxn];

bool is90(int a, int b, int c){
    return (a * a + b * b == c * c);
}

bool istriangle(int a, int b, int c){
    return (a + b > c && abs(a - b) < c);
}

int main(){
    int T, N;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
            scanf("%d", &len[i]);
        std::sort(len, len + N);
        int a = 0, b = 0, c = 0;
        for(int i = 0; i < N; i++)
            for(int j = i + 1; j < N; j++)
                for(int k = j + 1; k < N; k++){
                    if(istriangle(len[i], len[j], len[k]) && is90(len[i], len[j], len[k]) && len[i] * len[j] > a * b){
                        a = len[i]; b = len[j]; c = len[k];
                    }
                }
        printf("%d %d %d\n", a, b, c);
    }
    return 0;
}
