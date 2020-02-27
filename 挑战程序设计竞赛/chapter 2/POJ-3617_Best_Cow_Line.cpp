#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_N = 2000;
int N;
char S[MAX_N + 1];

void solve(){
    int a = 0, b = N - 1;
    int ans = 0;
    while (a <= b){
        bool left = false;
        for (int i = 0; i <= b - a; i++)
            if (S[a + i] < S[b - i]){
                left = true;
                break;
            }
            else if (S[a + i] > S[b - i]){
                left = false;
                break;
            }
        if (left) cout << S[a++];
        else cout << S[b--];
        ans += 1;
        if(ans % 80 == 0)
            cout << endl;
    }
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> S[i];
    solve();
    return 0;
}