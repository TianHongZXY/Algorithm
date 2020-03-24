//
// Created by TianHongZXY on 2020/3/17.
//
#include <bits/stdc++.h>	//万能头文件
#include <string.h>
#include <stdio.h>
using namespace std;

int main() {
    int number = 1;

    while (true) {
        int row, col;
        cin >> row;
        if (!row) break;
        cin >> col;
        char puzzle[20][20];
        int index[20][20];
        int id = 1;
        memset(index, 0, sizeof(index));
        memset(puzzle, 0, sizeof(puzzle));

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++) {
                cin >> puzzle[i][j];
                if (puzzle[i][j] != '*' && (i - 1 < 0 || j - 1 < 0 ||
                                            puzzle[i - 1][j] == '*' || puzzle[i][j - 1] == '*'))
                    index[i][j] = id++;
            }
        cout << "puzzle #" << number << ":" << endl;
        number++;
        char across[30];
        cout << "Across" << endl;
        for (int i = 0; i < row; i++) {
            int begin = 0;
            for (int j = 0; j <= col; j++) {
                if (puzzle[i][j] == '*' || puzzle[i][j] == '\0') {
                    if (j - begin > 0) {
                        strncpy(across, puzzle[i] + begin, j - begin);
                        across[j - begin] = '\0';
                        cout << "  " << index[i][begin] << "." << across << endl;
                    }
                    begin = j + 1;
                }
            }
        }

        cout << "Down" << endl;
        // 待做

    }
    return 0;

}