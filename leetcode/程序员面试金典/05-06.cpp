#include <bitset>
#include <iostream>
using namespace std;

int convertInteger(int A, int B) {
    bitset<32> a(A);
    bitset<32> b(B);
    cout << a << endl << b << endl;
    int res = 0;
    for(int i = 0; i < 32; i++)
        if(a[i] != b[i]) res++;

    return res;
}

int convertInteger(int A, int B) {
    bitset<32> res(A ^ B);
    return res.count();
}

int main() {
    int A, B;
    cin >> A >> B;

    int res = convertInteger(A, B);
    cout << res;

    return 0;
}
