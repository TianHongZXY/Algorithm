#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
const int maxn = 50 + 5;
double dist[maxn][maxn], d[maxn][maxn];
double x[maxn], y[maxn];

double distance(int i, int j){
    return sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
}

int main(){
    int n;
    while(scanf("%d", &n) == 1 && n){
        for(int i = 1; i <= n; i++) scanf("%lf%lf", &x[i], &y[i]);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dist[i][j] = distance(i, j);
        for(int j = 1; j < n - 1; j++)
            d[n-1][j] = dist[n-1][n] + dist[j][n];
        for(int i = n - 2; i >= 2; i--)
            for(int j = 1; j < i; j++)
                d[i][j] = min(d[i+1][j] + dist[i][i+1], d[i+1][i] + dist[j][i+1]);

        printf("%.2lf\n", dist[1][2] + d[2][1]);
    }
    
    return 0;
}