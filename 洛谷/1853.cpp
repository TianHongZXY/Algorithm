#include <cstdio>
#define max(x, y) (x > y ? x : y)
const int maxs = 5e6;
int W[11], V[11]; // 债券投资额，年收益
int f[maxs];
int s, n, d; // 本金，n年后，d债券种类

int main(){
    scanf("%d%d%d", &s, &n, &d);
    for(int i = 1; i <= d; i++)
        scanf("%d%d", &W[i], &V[i]);
    for(int k = 1; k <= n; k++){
        int gain = 0;
        for(int i = 1; i <= d; i++){
            for(int j = W[i]; j <= s; j += 1000){
                f[j] = max(f[j], f[j - W[i]] + V[i]);
                gain = max(gain, f[j]);
            }
        }
        s += gain;
    }
    printf("%d", s);

    return 0;    
}