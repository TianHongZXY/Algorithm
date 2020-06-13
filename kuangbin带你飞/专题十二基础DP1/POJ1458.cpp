#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#define max(x, y) ((x) > (y) ? (x) : (y))
using namespace std;
const int maxn = 1000 + 5;
int dp[maxn][maxn];
int main(){
    int lenx, leny;
    string X, Y;
    while(cin >> X >> Y){
        for(int i = 1; i <= X.size(); i++)
            for(int j = 1; j <= Y.size(); j++){
                if(X[i - 1] == Y[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        printf("%d\n", dp[X.size()][Y.size()]);
        memset(dp[0], 0, sizeof(dp[0]));
    }
}