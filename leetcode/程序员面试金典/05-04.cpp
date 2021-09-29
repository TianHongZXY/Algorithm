#include <algorithm>
#include <vector>
#include <bitset>
#include <iostream>
#include <cstdio>
using namespace std;


// vector<int> findClosedNumbers(int num) {
//     int n = __builtin_popcount(num);
//     int a, b;
//     for(a = num + 1; ; a++)
//         if(__builtin_popcount(a) == n) break;
//     for(b = num - 1; b > 0; b--)
//         if(__builtin_popcount(b) == n) break;
//     return {a > 0 ? a : -1, b > 0 ? b : -1};
//
// }
//

class Solution1 {
    public:
    int getNext(int n){
        int c = n;
        int c0 = 0, c1 = 0;
        while((c & 1) == 0 && c != 0){
            c >>= 1; c0++;
        }
        while((c & 1) == 1){
            c >>= 1; c1++;
        }
        int p = c0 + c1;
        if(p == 31 || p == 0) return -1;
        n |= (1 << p);
        n &= ~((1 << p) - 1);
        n |= (1 << (c1 - 1)) - 1;

        return n;
    }

    int getPrev(int n){
        int c = n;
        int c0 = 0, c1 = 0;
        while((c & 1) == 1){
            c1++; c >>= 1;
        }
        if(c == 0) return -1;
        while((c & 1) == 0){
            c0++; c >>= 1;
        }
        int p = c0 + c1;
        n &= ((unsigned int)(~0) << (p + 1));
        int mask = (1 << (c1 + 1)) - 1;
        n |= mask << (c0 - 1);
        return n;
    }

    vector<int> findClosedNumbers(int num) {
        vector<int> res;
        int next = getNext(num);
        int prev = getPrev(num);
        res.push_back(next);
        res.push_back(prev);

        return res;
    }
};

class Solution2 {
    public:
    vector<int> findClosedNumbers(int num){
        bitset<32> smaller(num);
        bitset<32> bigger(num);

        int s = -1;
        for (int i = 1; i < 31; i++) {
            if(smaller[i] == 1 && smaller[i - 1] == 0) {
                smaller.flip(i); smaller.flip(i - 1);
                for(int left = 0, right = i - 2; left < right; ) {
                    while(left < right && smaller[left] == 0) left++;
                    while(left < right && smaller[right] == 1) right--;
                    smaller.flip(left); smaller.flip(right);
                }
                s = (int)smaller.to_ulong();
                break;
            }
        }

        int b = -1;
        for (int i = 1; i < 31; i++) {
            if(bigger[i] == 0 && bigger[i - 1] == 1) {
                bigger.flip(i); bigger.flip(i - 1);
                for(int left = 0, right = i - 2; left < right; ) {
                    while(left < right && bigger[left] == 1) left++;
                    while(left < right && bigger[right] == 0) right--;
                    bigger.flip(left); bigger.flip(right);
                }
                b = (int)bigger.to_ulong();
                break;
            }
        }
        cout << b << " " << s << endl;
        return {b, s};
    }
    vector<int> findClosedNumbers1(int num) {
        bitset<32> small(num);
        bitset<32> bigger(num);

        int s = -1;
        // small, 10 转 01，1移到左侧
        for (int i = 1; i < 31; i++) {
            if (small[i] == 1 && small[i - 1] == 0) {
                small.flip(i);
                small.flip(i - 1);
                for (int left = 0, right = i - 2; left < right;) {
                    while (left < right && small[left] == 0) left++;
                    while (left < right && small[right] == 1) right--;
                    small.flip(left);
                    small.flip(right);
                }
                s = (int)small.to_ulong();
                break;
            }
        }

        // bigger, 01转10，1移到最右侧
        int b = -1;
        for (int i = 1; i < 31; i++) {
            if (bigger[i] == 0 && bigger[i - 1] == 1) {
                bigger.flip(i);
                bigger.flip(i - 1);

                for (int left = 0, right = i - 2; left < right;) {
                    while (left < right && bigger[left] == 1) left++;
                    while (left < right && bigger[right] == 0) right--;
                    bigger.flip(left);
                    bigger.flip(right);
                }
                b = (int)bigger.to_ulong();
                break;
            }
        }
        cout << b << " " << s << endl;
        return {b, s};
    }
};

int main(){
    int num;
    cin >> num;
    vector<int> res = Solution2().findClosedNumbers1(num);

    return 0;

}
