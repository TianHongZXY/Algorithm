#include <iostream>
#include <cstring>
#include <cstdio>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 15 + 5;
int tiles[maxn][maxn], state[maxn][maxn], tmp[maxn][maxn], res[maxn][maxn];
int M, N;

void flip(int row, int col){
    if(row > 0) state[row-1][col] ^= 1;
    if(col > 0) state[row][col-1] ^= 1;
    if(row < M - 1) state[row+1][col] ^= 1;
    if(col < N - 1) state[row][col+1] ^= 1;
    state[row][col] ^= 1;
}

int main(){
    while(cin >> M >> N){
        for(int i = 0; i < M; i++)
            for(int j = 0; j < N; j++)
                cin >> tiles[i][j];
        int ans = INF;
        for(int i = 0; i < (1<<N); i++){ // 枚举第一行的2^N个状态，分别对第一行每列有可能flip，也有可能不flip
            memset(tmp, 0, sizeof(tmp));
            memcpy(state, tiles, sizeof(state)); // state初始化为tiles开始的状态
            // 根据当前枚举的状态 i，对state第一行进行翻转，
            // 例如N = 3时，二进制 i = 00000101，则flip state第一行的第一列与第三列，记录此次flip操作到tmp中
            // 一共有00000000~00000111 八个状态
            // i从0开始，此时第一行一个都不翻，如果能成功，字典序也最小
            // 此后i逐渐增大，比如变为00000001，此时不往右移，即j = N - 1时，最后一列 = tmp[0][N-1] = 1，也让字典序最小，因此j要倒着来
            int cnt = 0;
            for(int j = N - 1; j >= 0; j--){ 
                if( ((i >> (N - 1 - j)) &1) == 1 ){ 
                    tmp[0][j] = 1;
                    flip(0, j);
                    cnt++;
                }
                // else tmp[0][j] = 0;
            }

            for(int ii = 1; ii < M; ii++)
                for(int jj = 0; jj < N; jj++)
                    if(state[ii-1][jj]){
                        flip(ii, jj);
                        cnt++;
                        tmp[ii][jj] = 1;
                    }
            
            int ok = 1;
            for(int ii = 0; ii < N; ii++)
                if(state[M-1][ii]){ ok = 0; break; }
            if(ok && cnt < ans){
                ans = cnt;
                memcpy(res, tmp, sizeof(res));
            }
        }

        if(ans == INF) cout << "IMPOSSIBLE" << endl;
        else{
            for(int i = 0; i < M; i++)
                for(int j = 0; j < N; j++)
                    printf("%d%c", res[i][j], j == N - 1 ? '\n' : ' ');
        }
    }
    return 0;
}