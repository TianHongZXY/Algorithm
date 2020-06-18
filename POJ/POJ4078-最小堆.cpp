#include <cstdio>
#include <vector>
using namespace std;
int N, ans = 0;
vector<int> heap;

void CreateHeap(int n){
    heap[++ans] = n;
    int i = ans;
    while(true){
        if(i <= 1)
            break;
        if(heap[i / 2] > heap[i]) // i / 2是i的父节点，如果父节点大了，就把i换上去
            swap(heap[i / 2], heap[i]);
        else break;
        i = i / 2;
    }
}

void DownHeap(){
    int k = 1;
    while(2 * k <= ans){ // 从根开始向下搜索左节点，如果超出了ans就越界了
        int j = 2 * k;
        if(j + 1 <= ans && heap[j] > heap[j + 1]) // 如果还有右节点，比较左右节点大小，j指向小的那个
            j = j + 1;
        if(heap[k] <= heap[j]) // 如果根比子节点小，break
            break;
        swap(heap[k], heap[j]);
        k = j; // 把k指向交换后的新位置，继续对heap[k]做下沉
    }
}

int main(){
    scanf("%d", &N);
    heap.resize(N + 5);
    int op, num;
    for(int i = 0; i < N; i++){
        scanf("%d", &op);
        if(op == 1){
            scanf("%d", &num);
            CreateHeap(num);
        }
        else{
            if(ans < 1) continue;
            printf("%d\n", heap[1]);
            swap(heap[1], heap[ans--]);
            DownHeap();
        }
    }
    // heap.clear();

    return 0;
}