// 题目链接 https://zhuanlan.zhihu.com/p/107194264?utm_source=qq
#include <cstdio>
const int maxn = 1e6 + 5;
const int m = 1e9 + 7;
int fibo[maxn];

void init_fibo(){
    fibo[0] = 0;
    fibo[1] = 1;
    for(int i = 2; i < maxn; i++)
        fibo[i] = (fibo[i - 1] + fibo[i - 2]) % m;
    return;
}

int main(){
    init_fibo();
    int T, N;
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        scanf("%d", &N);
        printf("%d\n", fibo[N]);
    }
    return 0;
}