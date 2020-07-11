// 题目链接 https://blog.csdn.net/weixin_39626452/article/details/95103839
// leetcode No.93 https://leetcode-cn.com/problems/restore-ip-addresses/
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int T;
    string ip;
    scanf("%d", &T);
    while(T--){
        cin >> ip;
        int len = ip.length();
        int i11, i22, i33, i44;
        string x;
        vector<string> res;
        for(int i = 0; i < len - 1 && i <= 2; i++){ // 在ith处插入点号，即在原ip的ip[i], ip[i+1]之间插入点号
            for(int j = i + 1; j < len - 1 && j <= i + 3; j++){
                for(int k = j + 1; k < len - 1 && k <= j + 3; k++){
                    if(len - 1 - k > 3 || (i + 1 > 1 && ip[0] == '0') || (j - i > 1 && ip[i + 1] == '0')
                    || (k - j > 1 && ip[j + 1] == '0') || (len - 1 - k > 1 && ip[k + 1] == '0')) continue;
                    string i1, i2, i3, i4;
                    i1 = ip.substr(0, i + 1); i11 = atoi(i1.c_str()); if(i11 > 255) continue;
                    i2 = ip.substr(i + 1, j - i); i22 = atoi(i2.c_str()); if(i22 > 255) continue;
                    i3 = ip.substr(j + 1, k - j); i33 = atoi(i3.c_str()); if(i33 > 255) continue;
                    i4 = ip.substr(k + 1, len - 1 - k); i44 = atoi(i4.c_str()); if(i44 > 255) continue;
                    x = i1 + '.' + i2 + '.' + i3 + '.' + i4;
                    // cout << x << endl;
                    res.push_back(x);
                }
            }
        }
    }
    return 0;
}