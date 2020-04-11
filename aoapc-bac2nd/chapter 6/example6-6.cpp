//
// Created by TianHongZXY on 2020/4/9.
//
#include <cstdio>
//#include <cstring>
//const int maxd = 20;
//int s[1<<maxd];

//int main(){
//    该解法超时
//    int D, I;
//    int t;
//    scanf("%d", &t);
//    while(scanf("%d", &D) && D != -1){
//        scanf("%d", &I);
//        memset(s, 0, sizeof(s));
//        int k, n = (1 << D) - 1;
//        for(int i = 0; i < I; i++){
//            int start = 1;
//            while(start < 1 << (D-1)){
//                if(s[start] == 0){ s[start] = !s[start]; start = 2 * start;}
//                else{ s[start] = !s[start]; start = 2 * start + 1;}
//            }
//            k = start;
//        }
//        printf("%d\n", k);
//    }
//
//    return 0;
//}

int main(){
    int D, I, t;
    scanf("%d", &t);
    while(t--){
        int k = 1;
        scanf("%d%d", &D, &I);
        // 可以直接一次得到最后一个小球(即编号为I的小球)到达的叶子节点
        for(int i = 0; i < D - 1; i++){
            // 对第I个来到当前层的小球，如果I是奇数，往左走 k = k*2，且编号I的小球将是第（I+1）/2 个来到下一层的小球
            if(I%2 == 1){k *= 2; I = (I + 1) / 2;}
            // 对第I个来到当前层的小球，如果I是偶数，往右走 k = k*2 + 1，且编号I的小球将是第 I/2 个来到下一层的小球
            else{k = 2*k + 1; I /= 2;}
        }
        printf("%d\n", k);
    }
    scanf("%d", &t);
    return 0;
}