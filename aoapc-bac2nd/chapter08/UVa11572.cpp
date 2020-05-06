#include <cstdio>
#include <set>
using namespace std;
const int maxn = 1000000 + 5;
int snow[maxn];
set<int> p;

int main(){
    int T, n;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &snow[i]);
        if(n <= 1) { printf("%d\n", n); continue; }
        int l = 0, r = 1, ans = 1; // [l, r]
        p.insert(snow[l]);
        while(r < n){
            if(p.count(snow[r])){
                ans = max(ans, r - l);
                while(snow[l] != snow[r]) { p.erase(snow[l]); l++; }
                l++;
            }
            else p.insert(snow[r]);
            r++;
        }
        ans = max(ans, r - l);
        printf("%d\n", ans);
        p.clear();
    }
    return 0;
}
