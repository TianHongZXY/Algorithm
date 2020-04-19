//
// Created by TianHongZXY on 2020/4/10.
//
#include <cstdio>
int t;

bool solve(int& W){
    // 输入一个子天平，返回子天平是否平衡，并将W修改为子天平的总重量
    int W1, D1, W2, D2;
    bool b1 = true, b2 = true;
    scanf("%d%d%d%d", &W1, &D1, &W2, &D2);
    if(!W1) b1 = solve(W1); // 递归，如果当前天平的W1为0，则判断其子天平是否平衡，并将W1变为其子天平重量之和
    if(!W2) b2 = solve(W2); // 同上
    W = W1 + W2; // 当前天平的总重量，给上一层(如果有)使用

    return b1 && b2 && (W1 * D1 == W2 * D2);
}

int main(){
    int w;
    scanf("%d", &t);
    while(t--){
        if(solve(w)) printf("YES\n"); else printf("NO\n");
        if(t) printf("\n");
    }
    return 0;
}
