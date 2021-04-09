#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
using namespace std;

class Solution {
public:
    int reverseBits(int num) {
        bitset<32> binary = bitset<32>(num);
        bool meet_zero = false;
        int i = 0;
        int maxlen = 0;
        int cur = 0;
        int last_zero = 0;
        while(i < binary.size()) {
            if(binary[i] == 1) {
                cur++; i++;
            }
            else {
                if (!meet_zero) {
                    last_zero = i;
                    cur++; i++;
                }
                else {
                    maxlen = max(cur, maxlen);  
                    i = last_zero + 1;
                    cur = 0;
                    if (maxlen >= binary.size() - i + 1)
                        break;
                }
                meet_zero = !meet_zero;
            }
        }
        return max(maxlen, cur);
    }
};



int reverseBits(int num) {
    bitset<32> binary = bitset<32>(num);
    for(int j = binary.size() - 1; j >= 0; j--) cout << binary[j] << " ";
    cout << endl;
    bool meet_zero = false;
    int i = 0;
    int maxlen = 0;
    int cur = 0;
    int last_zero = 0;
    while(i < binary.size()) {
        if(binary[i] == 1) {
            cur++; i++;
        }
        else {
            if (!meet_zero) {
                last_zero = i;
                cur++; i++;
            }
            else {
                maxlen = max(cur, maxlen);  
                i = last_zero + 1;
                cur = 0;
                if (maxlen >= binary.size() - i + 1)
                    break;
            }
            meet_zero = !meet_zero;
        }
    }
    return max(maxlen, cur);
}

int main() {
    printf("%d\n", reverseBits(2147483647));
}
