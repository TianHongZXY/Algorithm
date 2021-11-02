#include <iostream>
using namespace std;

int multiply(int A, int B) {
    return (B & 1 ? A : 0) + (B > 1 ? multiply(A + A, B >> 1) : 0);
}

int multiply(int A, int B) {
    // let A be the smaller one
    if(A > B) {
        int tmp = B;
        B = A;
        A = tmp;
    }
    int res = 0, cur = 0;
    while(A) {
        if(A & 1)
            res += B << cur;
        A >>= 1;
        ++cur;
    }
    return res;
}

int main() {
    int A, B;
    cin >> A >> B;
    int res = multiply(A, B);
    cout << res << endl;

    return 0;
}


