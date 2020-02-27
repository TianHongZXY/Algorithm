//
// Created by TianHongZXY on 2020/2/26.
//
#include <iostream>
using namespace std;

typedef long long ll;
const int MAX_N = 20000;
int N, L[MAX_N];

void solve(){
    ll ans = 0;
//  直到还剩一块板子时退出循环
    while (N > 1){
//      mii1和mii2分别是L中最短和次短板的索引
        int mii1 = 0;
        int mii2 = 1;
        if (L[mii1] > L[mii2]) swap(mii1, mii2);
        for (int i = 2; i < N; i++){
            if (L[i] < L[mii1]){
                mii2 = mii1;
                mii1 = i;
            }
            else if (L[i] < L[mii2])
                mii2 = i;
        }
        int t = L[mii1] + L[mii2];
        ans += t;
//      如果mii1刚好指向最后一块板，交换mii1和mii2，因为要合并板减小N，马上要丢弃最后一块板
        if (mii1 == N - 1) swap(mii1, mii2);
//      合并mii1和mii2两块板，存到L[mii1]处
        L[mii1] = t;
//      mii2处的板被合并入mii1，把索引最后一块板放到mii2处，当前板数 - 1
        L[mii2] = L[N-1];
        N--;
    }
    cout << ans << endl;
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> L[i];
    solve();
}