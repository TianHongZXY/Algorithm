#include <iostream>
#include <vector>
using namespace std;

int waysToStep(int n) {
    vector<int> res(n + 1);
    res[0] = 0; res[1] = 1; res[2] = 2; res[3] = 4;
    for(int i = 4; i <= n; i++)
        res[i] = ((res[i - 1] + res[i - 2] ) % 1000000007 + res[i - 3]) % 1000000007;
    return res[n];
}

int main() {
    int n;
    cin >> n;
    cout << waysToStep(n) << endl;
    return 0;
}
