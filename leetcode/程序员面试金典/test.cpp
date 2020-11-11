#include <vector>
#include <cstdio>
using namespace std;

int main(){
    vector<int> a = {1, 2, 3};
    for(int c : a)
        printf("%d", c);
    return 0;
}