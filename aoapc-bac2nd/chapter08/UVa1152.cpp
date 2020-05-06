#include <set>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 我的方法，用vector存A+B，-C-D，再排序，再对A+B的元素查找其在-C-D的上下界，之差即为个数，2190ms
// 当数字不大时比法二慢，出现很大的数字时我的相比起来更快，因为大数字哈希表查找起来很慢
int main(){
    int T, n;
    int a, b, c, d;
    scanf("%d", &T);
    int kase = 0;
    while(T--){
        vector<int> A, B, C, D, aaa, ccc;
        if(kase == 0){ kase++;} else cout << endl;
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d%d%d%d", &a, &b, &c, &d);
            A.push_back(a); B.push_back(b); C.push_back(c); D.push_back(d);
        }
        for(auto aa: A)
            for(auto bb: B)
                aaa.push_back(aa+bb);
        sort(aaa.begin(), aaa.end());
        for(auto cc: C)
            for(auto dd: D)
                ccc.push_back(-cc-dd);
        sort(ccc.begin(), ccc.end());
        int cnt = 0;
        for(auto x: aaa){
            int lo = lower_bound(ccc.begin(), ccc.end(), x) - ccc.begin();
            int hi = upper_bound(ccc.begin(), ccc.end(), x) - ccc.begin();
            cnt += (hi - lo);
        }
        cout << cnt << endl;
    }
    return 0;
}


// 法二，使用map，保存下A+B到map，对所有-C-D的组合去map中查找，6720ms，比我的慢
// #include <unordered_map>
// int A[4005], B[4005], C[4005], D[4005];
// int main_(){
//     int T, n;
//     scanf("%d", &T);
//     for(int k = 0; k < T; k++){
//         if(k != 0) cout << endl;
//         scanf("%d", &n);
//         for(int i = 0; i < n; i++) scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);
//         unordered_map<int, int> mp;
//         for(int i = 0; i < n; i++)
//             for(int j = 0; j < n; j++) mp[A[i] + B[j]]++;
//         int ans = 0;
//         for(int i = 0; i < n; i++)
//             for(int j = 0; j < n; j++) ans += mp[-C[i]-D[j]];
//         cout << ans << endl;
//     }
//     return 0;
// }   