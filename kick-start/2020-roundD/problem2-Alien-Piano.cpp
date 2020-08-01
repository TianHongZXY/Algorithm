#include <cstdio>
#define max(x, y) (x > y ? x : y)
const int maxk = 1e4 + 10;
int a[maxk];
// 题意：每有一个长度超过4的连续上升或连续下降子串，break rule次数+1
int main(){
    int T, K;
    scanf("%d", &T);
    for(int c = 1; c <= T; c++){
        scanf("%d", &K);
        for(int i = 0; i < K; i++)
            scanf("%d", &a[i]);
        int raise = 0, down = 0, ans = 0, prev = 0;
        for(int i = 0; i < K; i++){
            if(!i) { raise = down = 1; prev = a[i]; continue; }
            if(a[i] > prev){
                if(raise == 4){
                    ans++;
                    raise = 1;
                }
                else{
                    raise++;
                }
                down = 1;
                prev = a[i];
            }
            else if(a[i] < prev){
                if(down == 4){
                    ans++;
                    down = 1;
                }
                else{
                    down++;
                }
                raise = 1;
                prev = a[i];
            }
        }
        printf("Case #%d: %d\n", c, ans);
    }

    return 0;
}