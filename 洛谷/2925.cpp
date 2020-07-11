#include <cstdio>
#define max(x, y) (x > y ? x : y)
const int maxh = 5e3 + 5;
const int maxc = 5e4 + 5;
int C, H;
int f[maxc], v[maxh], s[maxh];

int main(){
    scanf("%d%d", &C, &H);
    for(int i = 1; i <= H; i++){
        scanf("%d", &v[i]);
        s[i] = s[i - 1] + v[i];
    }
    for(int i = 1; i <= H; i++){
        int bound = max(C - (s[H] - s[i]), v[i]);
        for(int j = C; j >= bound; j--)
            f[j] = max(f[j], f[j - v[i]] + v[i]);
    }
    printf("%d", f[C]);
    return 0;
}