#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 100000 + 1;
int A[maxn];
vector<int> squares;
// int squares[maxn * 100]; 
int sum(int i, int j){
    int ans = 0;
    for(int x = i; x <= j; x++){
        ans += A[x];
    }
    return ans;
}

int main(){
    int T, n, kase = 0;
    squares.push_back(0);
    for(int i = 1; i <= 3200; i++){
        squares.push_back(squares[i - 1] + (2 * i - 1));
    }
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &A[i]);
        int cnt = 0;
        int left = 0, right = 0, forward = 1, total = 0;
        while(left != n){
            if(forward){
                while(right < n){
                    total += A[right];
                    int idx = lower_bound(squares.begin(), squares.end(), total) - squares.begin();
                    if(squares[idx] == total) cnt++;
                    right++;
                }
                total -= A[left]; // 去掉A[left] 此时和为A[left+1 ~ n-1]
            }
            else{
                while(right > left){ // 此时right在n处，越界，A[n] = 0 不影响，left已右移，将right移动到left处为止
                    total -= A[right];
                    int idx = lower_bound(squares.begin(), squares.end(), total) - squares.begin();
                    if(squares[idx] == total) cnt++;
                    right--;
                }
                right++;
                total -= A[left];
            }
            forward ^= 1; // right将反向扫描
            left++; // 右移left
        }
        // for(int i = 0; i < n; i++){
        //     int total = 0;
        //     for(int j = i; j < n; j++){
        //         total += A[j];
        //         int idx = lower_bound(squares.begin(), squares.end(), total) - squares.begin();
        //         if(squares[idx] == total) cnt++;
        //     }
        // }
        printf("Case #%d: %d\n", ++kase, cnt);
        memset(A, 0, sizeof(A[0]) * (n + 10));
    }

    return 0;
}