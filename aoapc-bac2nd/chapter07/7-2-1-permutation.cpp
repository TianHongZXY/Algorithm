#include <cstdio>

void print_permutation(int n, int A[], int P[], int cur){
    if (cur == n){
        for(int i = 0; i < n; i++) printf("%d", A[i]); printf("\n");
    }
    else for(int i = 0; i < n; i++){
        if(!i || P[i-1] != P[i]){ // 防止出现 P = {1, 1, 1}，却有27个排列的重复情况
        int c1 = 0, c2 = 0;
            for(int j = 0; j < cur; j++) if (P[i] == A[j]) c1++;
            for(int j = 0; j < n; j++) if(P[i] == P[j]) c2++;
            int ok = 1;
            if(c1 < c2){ // 如果在P[i]还没在A中全部出现
                A[cur] = P[i];
                print_permutation(n, A, P, cur+1);
            }
        }
    }
}

int main(){
    int A[100];
    int P[] = {1, 1, 3, 3, 5, 7};
    // 按P的字典序输出全排列
    print_permutation(6, A, P, 0);

    return 0;
}