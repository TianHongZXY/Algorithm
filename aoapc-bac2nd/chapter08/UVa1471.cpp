#include <cstdio>
#include <set>
using namespace std;
const int maxn = 200000 + 5;
int a[maxn], g[maxn], f[maxn];

struct Candidate{
    int a, g;
    Candidate(int a, int g): a(a), g(g) {}
    bool operator < (const Candidate &rhs) const{
        return a < rhs.a;
    }
};
set<Candidate> s;
int main(){
    int T, n;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        g[0] = 1;
        for(int i = 1; i < n; i++)
            if(a[i] > a[i-1]) g[i] = g[i-1] + 1;
            else g[i] = 1;
        f[n-1] = 1;
        for(int i = n - 2; i >= 0; i--)
            if(a[i+1] > a[i]) f[i] = f[i+1] + 1;
            else f[i] = 1;
        s.clear();
        s.insert(Candidate(a[0], g[0]));
        int ans = 1;
        for(int i = 1; i < n; i++){ // 枚举i，此时s里包含的都是index < i的
            Candidate c = Candidate(a[i], g[i]);
            set<Candidate>::iterator it = s.lower_bound(c); // first one that is >= c
            bool keep = true;
            if(it != s.begin()){
            // 找到最大的j，使得 A[j] < A[i]
                Candidate last = *(--it); // (--it) points to the largest one that is < c
                ans = max(ans, f[i] + last.g); // 以为i开始和以j为结尾的子串长度和
                if(c.g <= last.g) keep = false; // 因为 i > j，且A[i] > A[j]，若 g[i] 却比 g[j] 小，则它无价值
            }
            if(keep){
                // s.erase(c); // 这行有没有都能ac，应该是序列没有重复的数，
                // 但如果有重复，假设含有 (20, 8)，且当前c是(20, 7), 但last是刚好在(20, 8)前面，所以last=(<20, 7)，而上面就会导致keep=false，所以不会发生这种情况
                s.insert(c);
                // 找到大于A[i]的候选项
                it = s.find(c); it++;
                // 如果它的a大，但是g却小于等于，无价值，抹掉
                while(it != s.end() && it->a > c.a && it->g <= c.g) s.erase(it++);
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}