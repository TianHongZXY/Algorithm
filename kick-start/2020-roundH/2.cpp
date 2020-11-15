#include <cstdio>
#include <string>
using namespace std;

bool isboring(int x){
    string sx = to_string(x);
    int flag = sx.length() % 2 == 0 ? 0 : 1;
    while(x){
        int lastdigit = x % 10;
        if(flag == 1 && x % 2 == 1) x /= 10;
        else if(flag == 0 && x % 2 == 0) x /= 10;
        else return false;
        flag = !flag;
    }
    return true;
}

int main(){
    int T, L, R, cnt;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
        scanf("%d%d", &L, &R);
        cnt = 0;
        for(int j = L; j <= R; j++)
            if(isboring(j)) cnt++;
        printf("Case #%d: %d\n", i, cnt);
    }
    return 0;
}