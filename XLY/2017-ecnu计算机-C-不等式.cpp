// https://acm.ecnu.edu.cn/problem/3304/
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
char line[100];
int above[210], below[210], equa[210];
int main(){
    int n, x, c;
    char op[5];
    scanf("%d", &n);
    getchar();
    int idx1 = 0, idx2 = 0, idx3 = 0;
    for(int i = 0; i < n; i++){
        cin.getline(line, 90);
        sscanf(line, "X %s %d", op, &c);
        if(op[0] == '=') equa[idx3++] = c;
        else if(op[0] == '>' && op[1] == '\0') above[idx1++] = c + 1;
        else if(op[0] == '>' && op[1] == '=') above[idx1++] = c;
        else if(op[0] == '<' && op[1] == '\0') below[idx2++] = c - 1;
        else if(op[0] == '<' && op[1] == '=') below[idx2++] = c;
        // printf("X %s %d\n", op, c);
    }
    sort(above, above + idx1);
    sort(below, below + idx2);
    sort(equa, equa + idx3);
    int ans = 0;
    for(int i = 0; i < idx3; i++){ // 遍历等于号的方程
        int ii = 0, jj = 0, kk = 0, cnt = 1;
        for(int k = i + 1; k < idx3; k++)
            if(equa[k] != equa[i]) break;
            else ii++;
        cnt += ii;

        for(int k = 0; k < idx1; k++)
            if(above[k] > equa[i]) break;
            else jj++;
        cnt += jj;

        for(int k = idx2 - 1; k >= 0; k--)
            if(below[k] < equa[i]) break;
            else kk++;
        cnt += kk;

        ans = max(cnt, ans);
    }

    for(int i = 0; i < idx1; i++){ // 遍历大于等于号
        int cnt = 0, ii = 0;
        cnt += (i + 1); // 严格满足第i个大于等于号方程时，小于i的方程都满足，反之不一定
        for(int k = idx2 - 1; k >= 0; k--)
            if(below[k] < above[i]) break;
            else ii++;
        cnt += ii;
        ans = max(cnt, ans);
    }

    for(int i = idx2 - 1; i >= 0; i--){ // 遍历小于等于号
        int cnt = 0, ii = 0;
        cnt += (idx2 - i); // 严格满足第i个小于等于号方程时，大于i的方程都满足，反之不一定
        for(int k = 0; k < idx1; k++)
            if(below[i] < above[k]) break;
            else ii++;
        cnt += ii;
        ans = max(cnt, ans);
    }
    printf("%d\n", ans);

    return 0;
}