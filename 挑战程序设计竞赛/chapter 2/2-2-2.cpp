#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100;
int N, S[MAX_N], T[MAX_N];
pair<int, int> itv[MAX_N];

void solve(){
    for (int i = 0; i < N; i++){
        itv[i].first = T[i];
        itv[i].second = S[i];
    }
    sort(itv, itv + N);

    int ans = 0, t = 0;
    for (int i = 0; i < N; i++)
        if (t < itv[i].second){
            t = itv[i].first;
            ans++;
        }
    cout << ans << endl;
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> S[i];
    }
    for (int i = 0; i < N; i++){
        cin >> T[i];
    }
    solve();
    return 0;
}