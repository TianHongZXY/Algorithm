#include <cstdio>
#include <cstring>
int main(){
    int n, cows[5];
    while(scanf("%d", &n) == 1 && n){
        memset(cows, 0, sizeof(cows));
        int ans = 0;
        cows[4] = 1;
        for(int i = 1; i <= n; i++){ // 到第i年
            // 先统计再生小牛
            if(i == n){
                for(int i = 0; i < 5; i++)
                    ans += cows[i];
                break;
            }
            cows[1] = cows[4]; // 今年新出生的牛

            cows[4] += cows[3]; // 明年又有牛达到成熟可以生了
            cows[3] = cows[2]; 
            cows[2] = cows[1];
            cows[1] = 0;
        }
        printf("%d\n", ans);
    }

    return 0;
}