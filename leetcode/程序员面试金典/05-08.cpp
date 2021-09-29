#include <vector>
#include <bitset>
#include <iostream>
using namespace std;

vector<int> drawLine(int length, int w, int x1, int x2, int y) {
    vector<int> res(length, 0);
    for(int i = x1; i <= x2; i++)
        res[i / 32 + y * w / 32] |= (1 << (31 - i % 32));
    return res; 
}

int main(){
    vector<int> result = drawLine(3, 32, 18, 28, 2);
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << endl;
    return 0;
}

