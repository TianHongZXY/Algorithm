#include <bitset>
using namespace std;

class Solution {
public:
    int insertBits(int N, int M, int i, int j) {
        bitset<32> NN = bitset<32>(N);
        bitset<32> MM = bitset<32>(M);
        for(int k = i; k <= j; k++)
            NN[k] = MM[k - i] == 1 ? 1 : 0;
        return NN.to_ulong();
    }
};

