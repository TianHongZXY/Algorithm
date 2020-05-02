#include <cstdio>

void print_subset(int n, int B[], int cur){
    // 位向量法
    if(cur == n){
        for(int i = 0; i < cur; i++)
            if(B[i]) printf("%d ", i);
        printf("\n");
        return;
    }

    B[cur] = 1; // 选cur
    print_subset(n, B, cur+1);
    B[cur] = 0; // 不选cur
    print_subset(n, B, cur+1);
}

void print_subset(int n, int s){ // 打印 {0, 1, 2,···, n-1}的子集S
    // 二进制法
    for(int i = 0; i < n; i++)
    if(s&(1<<i)) printf("%d ", i); // 非0即为真
    printf("\n");
}

int main(){
    int n = 5;
    for(int i = 0; i < (1<<n); i++)
        print_subset(n, i);
    printf("----------\n");
    int B[] = {1, 2, 3, 4, 5};
    print_subset(5, B, 0);
    return 0;
}