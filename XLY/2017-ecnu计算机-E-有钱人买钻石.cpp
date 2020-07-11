// dp方法，超时，只得54分
#include <cstdio>
#include <cstring>
#define max(x, y) (x > y ? x : y)
const int maxn = 5e7 + 10;
int f[maxn], num[5], cash[5] = {0, 1, 5, 10, 25};

int main(){
    int P;
    for(int i = 0; i < maxn - 10; i++) f[i] = -1;
    f[0] = 0;
    scanf("%d%d%d%d%d", &P, &num[1], &num[2], &num[3], &num[4]);
    for(int i = 1; i <= 4; i++){
        int nume = num[i];
        for(int k = 1; nume > 0; k = k << 1){
            if(k >= nume) k = nume;
            nume -= k;
            for(int j = P; j >= cash[i] * k; j--){
                if(f[j - cash[i] * k] < 0) continue;
                f[j] = max(f[j], f[j - k * cash[i]] + k);
            }
        }
    }
    if(f[P] == -1) printf("Impossible");
    else printf("%d", f[P]);
    return 0;
}