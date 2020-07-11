#include <cstdio>
#include <set>
using namespace std;
int N, Q;
const int maxn = 5e5 + 10;
const int maxa = 1e8 + 10;
int a[maxn], cnt[maxa];

int main(){
    int L, R;
    scanf("%d%d", &N, &Q);
    for(int i = 1; i <= N; i++)
        scanf("%d", &a[i]);
    while(Q--){
        set<int> s;
        scanf("%d%d", &L, &R);
        for(int i = L; i <= R; i++){
            s.insert(a[i]);
            cnt[a[i]]++;
        }
        int ans = 0;
        for(int x : s){
            if(cnt[x] == 2) ans++;
            cnt[x] = 0;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}