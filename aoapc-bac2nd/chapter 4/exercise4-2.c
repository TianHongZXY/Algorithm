//
// Created by TianHongZXY on 2020/3/25.
//
#include <stdio.h>
#define maxn 12

int main(){
    int n;
    int first = 1;
    while (scanf("%d", &n) == 1){
        int squares[maxn] = {0};
        int H[maxn][maxn] = {0};
        int V[maxn][maxn] = {0};
        int right[maxn][maxn] = {0};
        int down[maxn][maxn] = {0};
        int num_line;
        scanf("%d", &num_line);
        for(int i = 0; i < num_line; i++){
            char line;
            int x, y;
            getchar(); // 用来清除输入num_line时缓冲区的换行符
            scanf("%c %d %d", &line, &x, &y); // 不要用%s 不然会有bug
//          H的坐标为(行，列)
            if(line == 'H') H[x][y] = 1;
//          V的坐标为(列，行)
            else V[x][y] = 1;
        }
        for(int i = 1; i <= n; i++){
            for(int j = n-1; j >= 1; j--){
                if(H[i][j] == 1) right[i][j] = right[i][j+1] + 1;
                if(V[i][j] == 1) down[j][i] = down[j+1][i] + 1;
            }
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < n; j++){
                int maxlen = (right[i][j] > down[i][j]) ? down[i][j] : right[i][j];
                for(int k = 1; k <= maxlen; k++){
                    if (right[i+k][j] >= k && down[i][j+k] >= k){
                        squares[0] += 1;
                        squares[k] += 1;
                    }
                }
            }
        }
        if(first != 1) {
            printf("\n**********************************\n\n");
        }
        printf("Problem #%d\n\n", first);
        first++;
        if(squares[0] == 0) printf("No completed squares can be found.\n");
        else{
            for(int i = 1; i < n; i++){
                if(squares[i] != 0)
                    printf("%d square (s) of size %d\n", squares[i], i);
            }
        }
    }

    return 0;
}
