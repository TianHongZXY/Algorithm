#include <cstdio>
#include <map>
using namespace std;

int main(){
    int N, x;
    map<int, int> mp;
    while(scanf("%d", &N) == 1){
        for(int i = 0; i < N; i++){
            scanf("%d", &x);
            if(mp.count(x)) mp[x]++;
            else mp[x] = 1;
        }
        for(auto x : mp)
            if(x.second >= (N+1)/2){
                printf("%d\n", x.first);
                mp.clear(); break;
            }
    }
    return 0;
}