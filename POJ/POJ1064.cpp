#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 10000 + 10;
double cables[maxn];
int n, k;

// int partition(double a[], int lo, int hi){ // 闭区间[lo, hi]
//     double pivot = a[lo];
//     int i = lo, j = hi + 1;
//     while(true){
//         while(a[++i] < pivot) if(i >= hi) break;
//         while(a[--j] > pivot) if(j <= lo) break;
//         if(i >= j) break;
//         swap(a[i], a[j]);
//     }
//     swap(a[lo], a[j]); // 跳出循环时，j所指的是小于pivot的位置，i指的是大于pivot的位置，所以pivot应该放到j处
//     return j;
// }

// void q_sort(double a[], int lo, int hi){ // 闭区间[lo, hi]
//     if(lo >= hi) return;
//     int j = partition(a, lo, hi);
//     q_sort(a, lo, j - 1);
//     q_sort(a, j + 1, hi);
// }

// int binary_search(double a[], int lo, int hi, double target){
//     while(lo < hi){
//         int mid = lo + (hi - lo) / 2;
//         if(a[mid] == target) return mid;
//         else if(a[mid] > target) hi = mid - 1;
//         else lo = mid + 1;
//     }
//     if(a[lo] > target) return lo;
//     else return lo + 1; // 返回刚好比target大的位置
// }

int kpieces(int len){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cnt += floor(cables[i] / len);
    }
    return cnt >= k;
}

int main(){
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%lf", &cables[i]);
        cables[i] *= 100;
    }
    // q_sort(cables, 0, n - 1);
    // for(int i = 0; i < n; i++)
        // printf("%lf ", cables[i]);
    int lo = 1, hi = 10000000, ans = 0;
    // printf("\n%d", binary_search(cables, 0, n - 1, 8.03));
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(kpieces(mid)){
            lo = mid + 1;
            ans = max(ans, mid);
        }
        else{
            hi = mid - 1;
        }
    }
    printf("%.2f\n", (double)ans / 100.0); // 不要用 %lf，会报错，只用 %.f！
    return 0;
}