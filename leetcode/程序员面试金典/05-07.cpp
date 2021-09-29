#include <bitset>
#include <iostream>
using namespace std;

int exchangeBits(int num) {
    int res = ((num & 1431655765) << 1) | ((num & -1431655766) >> 1);
    return res;
    // 5在16进制是二进制的0101，a在16进制是二进制的1010
    // return ((num & 0x55555555) << 1) | ((num & 0xaaaaaaaa) >> 1);
}

int main() {
    int num;
    cin >> num;
    exchangeBits(num);
    return 0;
}
