#include <cstdio>
#define max(x, y) (x > y ? x : y)
const int maxn = 2e5 + 10;
int a[maxn];

int main(){
    int T, N;
    scanf("%d", &T);
    for(int c = 1; c <= T; c++){
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
            scanf("%d", &a[i]);
        a[N] = -1;
        int record = -1;
        int ans = 0;
        for(int i = 0; i < N; i++){
            if(a[i] > record){
                record = a[i];
                if(a[i] > a[i + 1])
                    ans++;
            }
        }
        printf("Case #%d: %d\n", c, ans);
    }
    
    return 0;
}