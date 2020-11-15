#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#define INF 0x3f3f3f3f
#define min(x, y) (x < y ? x : y)
const int maxn =  150;
int n, d[maxn][maxn]; // d[i][j] 从i点到j点的最短路长度
using namespace std;


void init(){
    memset(d, 0x3f, sizeof(d));
    for(int i = 1; i <= n; i++)
        d[i][i] = 0;
}

void floyd(){
    // init();
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(d[i][k] < INF && d[k][j] < INF)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main(){
    int T, Q, A, B;
    string name;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
        scanf("%d%d", &n, &Q);
        bitset<26> namesbit[maxn];
        for(int j = 1; j <= n; j++){
            cin >> name;
            for(int k = 0; k < name.length(); k++)
                namesbit[j][name[k] - 'A'] = 1;
        }
        init();
        for(int j = 1; j <= n; j++){
            for(int k = j + 1; k <= n; k++){
                if((namesbit[j] & namesbit[k]).count())
                    d[j][k] = d[k][j] = 1;
            }
        }
        floyd();
        printf("Case #%d:", i);
        for(int j = 0; j < Q; j++){
            scanf("%d%d", &A, &B);
            printf(" %d", d[A][B] < INF ? d[A][B] + 1 : -1);
        }
        printf("\n");
    }
    return 0;
}
