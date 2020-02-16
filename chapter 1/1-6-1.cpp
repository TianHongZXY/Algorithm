#include <iostream>
#include <algorithm>
using namespace std;


const int MAX_N = 100;
int n, a[MAX_N];

int solve(){
    // O(N^3)
    int ans = 0;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++){
                int len = a[i] + a[j] + a[k];
                int ma = max(a[i], max(a[j], a[k]));
                if (len - ma > ma)
                    ans = len;
            }
    return ans;
}

int solve_2(){
    // 先排序，再遍历 O(NlogN)
    sort(a, a+n);
    for (int i = n-1;i >= 2; i--){
        if (a[i] < a[i-1] + a[i-2])
            return a[i] + a[i-1] + a[i-2];

    }
    return 0;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int ans = solve_2();
    cout << ans << endl;
    return 0;
}
