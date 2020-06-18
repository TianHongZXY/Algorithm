#include <cstdio>
#define max(x, y) ((x) > (y) ? (x) : (y)) 
const int maxn = 100000;
int cost[maxn];
int M, N;

int check(int target){
    int fajo = 1, sum = 0; // 最后一个月没在循环中加上
    for(int i = 0; i < N; i++){
        if(sum + cost[i] > target){
            sum = cost[i];
            fajo++;
        }
        else sum += cost[i];
    }
    return fajo;
}

int main(){
    scanf("%d%d", &N, &M);
    int right = 0, left = 0;
    for(int i = 0; i < N; i++){
        scanf("%d", &cost[i]);
        left = max(cost[i], left);
        right += cost[i];
    }
    while(left < right){ // 这是一个求左边界的二分搜索
        int mid = left + (right - left) / 2;
        if(check(mid) <= M){ // 即二分搜索中 mid >= target
            right = mid;
        }
        else{ // mid < target
            left = mid + 1;
        }
    }
    printf("%d\n", left);

    return 0;
}