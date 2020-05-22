#include <cstdio>
#include <cstring>
#include <algorithm>
// #define min(x, y) ( ((x) < (y)) ? (x) : (y) )
using namespace std;
const int maxn = 100 + 10;
int n, d[maxn][maxn];
char S[maxn];

bool match(char a, char b){
    return ((a == '(' && b == ')') || (a == '[' && b == ']'));
}

void dp(){
    for(int i = 0; i < n; i++){
        d[i+1][i] = 0; // 空字符不用补
        d[i][i] = 1; // 单字符，补全需要1个字符
    }
    for(int i = n - 2; i >= 0; i--)
        for(int j = i + 1; j < n; j++){
            d[i][j] = n;
            if(match(S[i], S[j])) d[i][j] = min(d[i][j], d[i+1][j-1]);
            for(int k = i; k < j; k++)
                d[i][j] = min(d[i][k] + d[k+1][j], d[i][j]);
        }
}

void print(int i, int j){
    if(i > j) return;
    if(i == j){
        if(S[i] == '(' || S[i] == ')') printf("()");
        else printf("[]");
        return;
    }
    int ans = d[i][j];
    if(match(S[i], S[j]) && ans == d[i+1][j-1]){
        printf("%c", S[i]); print(i+1, j-1); printf("%c", S[j]);
        return;
    }
    for(int k = i; k < j; k++)
        if(ans == d[i][k] + d[k+1][j]){
            print(i, k); print(k+1, j);
            return;
        }
}

int main(){
    int T;
    scanf("%d", &T);
    getchar();
    while(T--){
        getchar();
        fgets(S, maxn, stdin);
        // getline(cin, S);
        n = strlen(S) - 1; // fgets会保留换行符，再在换行符后添加'\0’
        memset(d, -1, sizeof(d));
        dp();
        print(0, n - 1);
        printf("\n");
        if(T) printf("\n");
    }


    return 0;
}