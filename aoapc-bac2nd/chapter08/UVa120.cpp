#include <cstdio>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
int n, pancake[30 + 5];
void flip(int k){
    int last = n - k + 1; // 从1~n-k+1颠倒
    for(int i = 1; i <= last / 2; i++){
        swap(pancake[i], pancake[last - i + 1]);
    }
}

int main(){
    string line;
    while(getline(cin, line) && line != ""){
        stringstream ss(line);
        n = 1;
        while(ss >> pancake[n++]) continue;
        n--; n--; // pancake[1]~pancake[n]为煎饼
        // for(int i = 1; i <= n; i++) printf("%d%c", pancake[i], i == n ? '\n':' ');
        cout << line << endl;
        int bottom = 1, max = -1, maxidx;
        while(!is_sorted(pancake+1, pancake+n+1)){
            for(int i = 1; i <= n - bottom + 1; i++){
                if(pancake[i] > max) {max = pancake[i]; maxidx = i;}
            }
            int flipidx = n - maxidx + 1; // pancake存的是从上往下1234，flip时是从下往上1234
            if(flipidx == bottom) bottom++;
            else if(maxidx == 1){
                flip(bottom);
                printf("%d ", bottom++);
            }
            else{
                flip(flipidx);
                printf("%d ", flipidx);
            }
            max = -1;
        }
        printf("0\n");
    }
    return 0;
}

// 法二
// int pc[32], n;
// int main() {
//     string line;
//     while (getline(cin, line)) {
//         cout <<line <<endl; // 输出原序列
//         stringstream input(line); n = 0;
//         while (input >>pc[n]) n ++; // 分割得到所有数字
//         for (int i=0; i < n-1; i ++) { // 从大到小依次归位煎饼
//             int pos = max_element(pc, pc+n-i) - pc; // 找到最大值的下标
//             if (pos != n-i-1) { // 未正常归位
//                 if (pos != 0) { // 不在栈顶
//                     printf("%d ", n - pos); // 输出位置
//                     reverse(pc, pc+pos+1); // 翻转到最上层
//                 }
//                 printf("%d ", i+1); // 第二次输出
//                 reverse(pc, pc+n-i); // 翻转到正确位置
//             }
//         } 
//         puts("0");
//     }
//     return 0;
// }