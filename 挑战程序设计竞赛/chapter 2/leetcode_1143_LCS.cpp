//
// Created by TianHongZXY on 2020/2/26.
//
using namespace std;

const int MAX_N = 1000, MAX_M = 1000;
int dp[MAX_N + 1][MAX_M + 1];
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++){
                if (text1[i] == text2[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
                else dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        return dp[n][m];
    }
};