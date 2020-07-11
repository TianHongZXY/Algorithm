#include <cstdio>
#include <algorithm>
#define max(x, y) (x > y ? x : y)
#define min(x, y) (x < y ? x : y)
using namespace std;
const int maxn = 250000 + 10;
int n, m;
pair<int, int> st[maxn];
int q, q1;
long long q2 = 0;

void solve1(){
    int ans = 0;
    for(int k = 1; k <= n; k++){
        int i = st[k].first;
        if(i == st[k - 1].first) continue;
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            if(i >= st[j].first && i <= st[j].second) cnt++;
            else if(i < st[j].first) break;
        }
        ans = max(ans, cnt);
    }
    printf("%d\n", ans);
}

void solve2(){
    long long numer = min(q2, m), denom = max(q2, m);
    long long r = denom % numer;
    while(r){
        denom = numer;
        numer = r;
        r = denom % numer;
    }
    printf("%lld/%lld\n", q2 / numer, m / numer);
    return;
}

int main(){
    int s, t;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &s, &t);
        st[i] = make_pair(s, t);
        q2 += (t - s + 1);
        // r[i] = i;
    }
    std::sort(st + 1, st + 1 + n);
    scanf("%d", &q);
    if(q == 1) solve1();
    if(q == 2) solve2(); 
    if(q == 3) { solve1(); solve2(); }

    return 0;
}