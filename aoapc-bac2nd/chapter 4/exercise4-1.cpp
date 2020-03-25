//
// Created by TianHongZXY on 2020/3/23.
// 过了udebug的1000个实例，没能过UVA，不知道问题出在哪
// 最终过了UVA，发现问题主要在读取数据，单纯用scanf无法AC，把文件后缀改成cpp，用了cin.getline才AC了
#include<iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

// 棋盘坐标 1~10, 1~9
int table[11][10];
char table_c[11][10];
int red[10][2];
int is_checkmated(int bx, int by, int rx, int ry, char r){
    int is_checkmated = 0;
    if (r == 'G'){
        if(by == ry) {
            for (int i = bx + 1; i < rx; i++){
                if (table[i][by] == 1)
                    return 0;
            }
            is_checkmated = 1;
        }
    } else if (r == 'R'){
        if (by == ry){
            if (rx > bx){
                for (int i = bx + 1; i < rx; i++){
                    if (table[i][by] == 1)
                        return 0;
                }
            }
            else{
                for (int i = rx + 1; i < bx; i++){
                    if (table[i][by] == 1)
                        return 0;
                }
            }
            is_checkmated = 1;
        } else if (bx == rx){
            if (ry > by){
                for (int i = by + 1; i < ry; i++){
                    if (table[bx][i] == 1)
                        return 0;
                }
            }
            else{
                for (int i = ry + 1; i < by; i++){
                    if (table[bx][i] == 1)
                        return 0;
                }
            }
            is_checkmated = 1;
        }
    } else if (r == 'C'){
        int count = 0;
        if (by == ry){
            if (rx > bx){
                for (int i = bx + 1; i < rx; i++){
                    if (table[i][by] == 1)
                        count++;
                }
                if (count != 1) return 0;
            }
            else{
                for (int i = rx + 1; i < bx; i++){
                    if (table[i][by] == 1)
                        count++;
                }
                if (count != 1) return 0;
            }
            is_checkmated = 1;
        } else if (bx == rx){
            if (ry > by){
                for (int i = by + 1; i < ry; i++){
                    if (table[bx][i] == 1)
                        count++;
                }
                if (count != 1) return 0;
            }
            else{
                for (int i = ry + 1; i < by; i++){
                    if (table[bx][i] == 1)
                        count++;
                }
                if (count != 1) return 0;
            }
            is_checkmated = 1;
        }
    } else if (r == 'H'){
        int possible_move[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
        int hobbing[8][2]    =    {{-1,  0}, {-1, 0}, {0,  -1}, {0,  1}, {0, -1}, {0, 1}, {1,  0}, {1, 0}};
        for(int i = 0; i < 8; i++){
            if ( (rx+possible_move[i][0] == bx) && (ry+possible_move[i][1] == by) ){
                if (table[rx+hobbing[i][0]][ry+hobbing[i][1]] == 0){
                    is_checkmated = 1;
                    break;
                }
            }
        }
    }

    return is_checkmated;
}

int main(){
    char xyz[101];
    int move[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    while(1){
        // gx gy分别为黑方将军横纵坐标
        int n, bx, by;
        scanf("%d%d%d", &n, &bx, &by);
        if(n == 0) break;
        int rx, ry;
        char r;
        memset(table, 0, sizeof(int) * 110);
        memset(table_c, 0, sizeof(char) * 110);
        getchar();
        for(int i = 0; i < n; i++) {
            cin.getline(xyz,101);
            sscanf(xyz,"%c %d %d",&r,&rx,&ry);
//            scanf("%s%d%d", &r, &rx, &ry);
            table[rx][ry] = 1;
            table_c[rx][ry] = r;
            red[i][0] = rx;
            red[i][1] = ry;
        }

        int is_checked = 1;
        for (int i = 8; i <= 10; i++){
            for(int j = 4; j <= 6; j++){
                if (table_c[i][j] == 'G' && j == by){
                    // 如果开局红帅能直接将黑帅，则黑帅直接将掉红帅
                    if(is_checkmated(bx, by, i, j, 'G') == 1){
                        is_checked = 0;
                        break;
                    }
                }
            }
        }
        if (is_checked == 0){
            printf("NO\n");
            continue;
        }
        for(int i = 0; i < 4; i++){
            int new_bx = bx + move[i][0];
            int new_by = by + move[i][1];
            // 黑将军移动范围越界
            if(new_bx > 3 || new_bx < 1 || new_by < 4 || new_by > 6) continue;
            // 假设这次合法移动能不被将军
            is_checked = 0;
            int eated = 0;
            if (table[new_bx][new_by] == 1){
                eated = 1;
                table[new_bx][new_by] = 0;
            }
            // 对红方每个棋子判断能否将军
            for(int j = 0; j < n; j++){
                // 假如有红子被黑子吃掉的情况
                if (eated)
                    // 如果被吃的就是当前的子，跳过
                    if(red[j][0] == new_bx && red[j][1] == new_by) continue;
                // 假如第j个红子能将军，打断循环
                if(is_checkmated(new_bx, new_by, red[j][0], red[j][1], table_c[red[j][0]][red[j][1]])){
                    is_checked = 1;
                    break;
                }
            }
            // 如果这次移动有过eated，恢复那个棋子
            if (eated) {table[new_bx][new_by] = 1;}
            // 如果每个红子都不能将军，则此次不被将军
            if (is_checked == 0) break;

        }
        if (is_checked)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}