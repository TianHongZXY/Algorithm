#include <cstdio>
#define max(a, b) ( ((a)>(b)) ? (a):(b) )
#define min(a, b) ( ((a)>(b)) ? (b):(a) )

// 复杂度O(nlogn)
int maxsum(int A[], int x, int y){ // 数组A的开区间[x, y)子序列最大和
    if(y - x == 1) return A[x]; // 一个元素 返回它
    int m = x + (y - x) / 2; // 划分左右子区间
    int maxs = max(maxsum(A, x, m), maxsum(A, m, y)); // 找出[x, y)左右子区间能得到的最大和
    int v = 0, L = A[m - 1], R = A[m]; // L为从m-1到x能得到的最大和，R为从m到y-1能得到的最大和
    for(int i = m - 1; m >= x; i--) L = max(L, v + A[i]);
    for(int j = m; j < y; j++) R = max(R, v + A[j]);
    return max(maxs, L+R); // 区间[x, y)的子序列最大和可能在其左右两个更小的区间里，也可能是从其中间延伸到两边的这个区间里
}

// 复杂度O(n)
int maxsum_2(int A[], int n){
    int S[n + 1]; S[0] = 0;
    int lmin = 0, ans = S[1];
    for(int i = 1; i <= n; i++){
        S[i] = S[i - 1] + A[i]; // S[i]为数组A前i个元素和
        ans = max(ans, S[i] - lmin); // 答案是max(ans, 1~i的序列和 - i前面的最小子序列和)
        lmin = min(S[i], lmin); // lmin是S[1]~S[i-1]最小的那个，再将当前S[i]考虑进来
    }

    return ans;
}

// 复杂度O(n)
int maxsum_3(int a[],int n){
    int ThisSum = 0, MaxSum = 0;    
    for(int j = 0; j < n; j++){
        ThisSum += a[j];
        if(ThisSum > MaxSum){
            MaxSum = ThisSum;
        }else if (ThisSum < 0){
            ThisSum = 0;        //ThisSum < 0，说明跨越a[j]不能使序列和变大
        }
    }
    return MaxSum;
}