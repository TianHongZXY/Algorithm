// #include <iostream>
// #include <climits>
// using namespace std;
// bool found;
// int n;
// void dfs(long long m, int k){
//     // 没法过01序列长度超过19的数字n，但是可以AC POJ，因为最长的序列是n=198时，刚好是19位
//     if(found) return;
//     if(k > 19) return;
//     if(m % n == 0){
//         found = true;
//         cout << m << endl;
//         return;
//     }
//     dfs(m * 10, k + 1);
//     dfs(m * 10 + 1, k + 1);
// }

// int main(){
//     unsigned long long m;
//     while(cin >> n && n){
//         m = 1; found = false;
//         dfs(m, 1);
//     }
//     return 0;
// }
#include <iostream>
using namespace std;
int mod[524286];

int main(){
    int n;
    while(cin >> n && n){
        int i = 1;
        mod[1] = 1 % n;
        for(i = 2; mod[i - 1] != 0; i++){
            //mod[i/2]*10+i%2模拟了BFS的双入口搜索
            mod[i] = (mod[i / 2] * 10 + i % 2) % n; // i%2是让i奇数时+1,偶数时+0，分层bfs时i的上一层为i/2
        }
        // 退出时 mod[i-1] == 0，所以i退一步
        i--;
        int pm = 0;
        while(i){
            mod[pm++] = i % 2; // 这步把*10操作转化为%2操作，逆向求倍数的每一位数字，具体如何证明还未知
            i /= 2;
        }
        while(pm){
            cout << mod[--pm];
        }
        cout << endl;
    }
    return 0;
}