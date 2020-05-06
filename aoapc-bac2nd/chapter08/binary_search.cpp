int bsearch(int A[], int x, int y, int v){
    int m;
    while(x < y){
        m = x + (y - x) / 2;
        if(A[m] == v) return m;
        else if(A[m] > v) y = m;
        else x = m + 1;
    }
    return -1;
}

int lower_bound(int A[], int x, int y, int v){
    // 当v存在时返回它的第一个位置，不存在时返回插入它仍不改变排列顺序的位置
    int m;
    while(x < y){
        m = x + (y - x) / 2;
        if(A[m] >= v) y = m;
        else x = m + 1;
    }
    return x;
}

int upper_bound(int A[], int x, int y, int v){
    // 当v存在时返回它的最后一个位置的下一个位置，不存在时返回插入它仍不改变排列顺序的位置
    int m;
    while(x < y){
        m = x + (y - x) / 2;
        if(A[m] <= v) x = m + 1;
        else y = m;
    }
    return x;
}

int main(){
    int A[] = {1,1,3,3,5,7,8,9,9,11};
    // 对于一个v，它在A中出现的序列是[L, R)
    int L = lower_bound(A, 0, sizeof(A)/sizeof(A[0]), 9);
    int R = upper_bound(A, 0, sizeof(A)/sizeof(A[0]), 9);

    return 0;
}