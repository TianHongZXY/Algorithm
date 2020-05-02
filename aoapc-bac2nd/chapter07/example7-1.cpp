#include <cstdio>
#include <string>
#include <unordered_set>
using namespace std;

int main(){
    int N, kase = 0;
    while(scanf("%d", &N) == 1 && N){
        if(kase) printf("\n"); else kase++;
        char buf[100]; string s; bool hassolution = false;
        for(int fj = 1234; ; fj++){
            sprintf(buf, "%05d%05d", fj*N, fj);
            s = buf;
            if(s.size() > 10) break;
            unordered_set<char> _set(s.begin(), s.end());
            if(_set.size() == 10){
                printf("%05d / %05d = %d\n", fj*N, fj, N);
                hassolution = true;
            }
        }
        if(!hassolution) printf("There are no solutions for %d.\n", N);
    }

    return 0;
}