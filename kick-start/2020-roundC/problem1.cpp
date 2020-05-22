#include <cstdio>
const int maxn = 200000 + 10;
int A[maxn];

int main(){
    int T, n, k, kase = 0;
    scanf("%d", &T);
    while(T--){
        int cnt = 0, meetk = 0;
        scanf("%d%d", &n, &k);
        for(int i = 0; i < n; i++){
            scanf("%d", &A[i]);
            if(meetk){
                if(A[i] != A[i-1] - 1) meetk = 0;
                else if(A[i] == 1) { cnt++; meetk = 0; }
            }
            if(A[i] == k) meetk = 1;
        }
        printf("Case #%d: %d\n", ++kase, cnt);
    }

    return 0;
}