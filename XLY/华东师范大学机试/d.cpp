#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

// struct BigInteger{
//     static const int BASE = 100000000;
//     static const int WIDTH = 8;
//     vector<int> s;

//     BigInteger(long long num = 0) { *this = num; }
//     BigInteger operator = (long long num){
//         s.clear();
//         do{
//             s.push_back(num % BASE);
//             num /= BASE;
//         }while(num > 0);
//         return *this;
//     }
//     BigInteger operator = (const string& str){
//         s.clear();
//         int x, len = (str.length() - 1) / WIDTH + 1;
//         for(int i = 0; i < len; i++){
//             int end = str.length() - i * WIDTH;
//             int start = max(0, end - WIDTH);
//             sscanf(str.substr(start, end - start).c_str(), "%d", &x);
//             s.push_back(x);
//         }
//         return *this;
//     }
// };


int main(){
    int T, x, y;
    double res;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &x, &y);
        int ans = 1;
        for(int i = 1; i <= y; i++){
            ans = (ans % mod * x;
        }
    }
    return 0;
}