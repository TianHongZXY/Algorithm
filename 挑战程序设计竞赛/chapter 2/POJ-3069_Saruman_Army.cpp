//
// Created by TianHongZXY on 2020/2/25.
//
#include <iostream>
#include <algorithm>
using namespace std;


const int MAX_N = 1000;
int X[MAX_N];
int N, R;

void solve(){
    sort(X, X + N);
    int i = 0, ans = 0;
    while (i < N){
//        s是当前最左边点的位置
        int s = X[i++];
//        一直向右直到找到第一个距离s超出R的点X[i]
        while (i < N && X[i] <= s + R) i++;
//        p是新加上标记的点的位置
        int p = X[i - 1];
//        同上，找到第一个距离p超出R的点
        while (i < N && X[i] <= p + R) i++;
//        标记的点总数+1，接下来从第一个没被p点覆盖的点继续向右搜索
        ans++;
    }
    cout << ans << endl;
}

int main(){
    while (true){
        cin >> R >> N;
        if (R == -1 and N == -1)
            break;
        for (int i = 0; i < N; i++)
            cin >> X[i];
        solve();
    }
    return 0;
}