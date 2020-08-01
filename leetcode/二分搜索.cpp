#include <cstdio>
#define GET_ARRAY_LEN(array,len) {len = (sizeof(array) / sizeof(array[0]));}
#include <vector>
using namespace std;

// 寻找一个数的二分搜索
int binary_search(int nums[], int n, int target){
    int left = 0;
    int right = n - 1;
    while(left <= right){ // 因为在这里取等号, 所以必须同时收缩left和right, 防止死循环
        int mid = left + (right - left) / 2; // 对于目标区域长度为奇数而言，是处于正中间的，对于长度为偶数而言，是中间偏左的。
        // 因此左右边界相遇时，只会是以下两种情况：
            // left, mid 指向同一个数，right指向它的下一个数
            // left, mid, right 指向同一个数
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
            right = mid - 1;
        else if(nums[mid] < target)
            left = mid + 1;
    }
    return -1;
}

// 寻找左侧边界的二分搜索，即第一个大于等于target的index
int lower_bound(int nums[], int n, int target){
    if(n == 0) return -1;
    int left = 0, right = n; // 搜索区间左闭右开[left, right)
    while(left < right){ // 当搜索的区间为[left, left)时为空，退出循环
        int mid = left + (right - left) / 2; // mid在中间靠左，等于在往左边收缩，等于收缩右边界
        if(nums[mid] >= target){
            right = mid; // 因为搜索区间为左闭右开，这时相当于把区间缩到[left, mid)，而right始终在搜索右边界保持大于等于target，除非left也越界不然不会碰头
        }
        else if(nums[mid] < target){
            left = mid + 1; // 收缩左边界
        }
    }
    return right; // right一定会是大于等于target的。不过跳出循环时left==right，其实都一样
}

// lower_bound的左闭右闭写法
// int lower_bound_close_form(int nums[], int n, int target) {
//     int left = 0, right = n - 1;
//     // 搜索区间为 [left, right]
//     while (left <= right) {
//         int mid = left + (right - left) / 2;
//         if (nums[mid] < target) {
//             // 搜索区间变为 [mid+1, right]
//             left = mid + 1;
//         } else if (nums[mid] >= target) {
//             // 搜索区间变为 [left, mid-1]
//             right = mid - 1;
//         }
//     }
//     // 检查出界情况
//     // if (left >= n || nums[left] != target)
//         // return -1;
//     return left;
// }

// 寻找右侧边界的二分搜索，即第一个大于target的index
int upper_bound(int nums[], int n, int target){
    if(n == 0) return -1;
    int left = 0, right = n; // 搜索区间左闭右开[left, right)
    while(left < right){ // 当搜索的区间为[left, left)时为空，退出循环
        int mid = left + (right - left) / 2;
        if(nums[mid] <= target){
            left = mid + 1; // 这时相当于把区间缩到[mid + 1 right)，排除了mid
        }
        else if(nums[mid] > target){
            right = mid; // 收缩右边界，right一定是大于target的，此时搜索[left, mid)
        }
    }
    return right; // right一定会是大于target的。不过跳出循环时left==right，其实都一样
}

// int upper_bound_close_form(int nums[], int n, int target) {
//     int left = 0, right = n - 1;
//     while (left <= right) {
//         int mid = left + (right - left) / 2;
//         if (nums[mid] < target) {
//             left = mid + 1;
//         } else if (nums[mid] > target) {
//             right = mid - 1;
//         } else if (nums[mid] == target) {
//             // 这里改成收缩左侧边界即可
//             left = mid + 1;
//         }
//     }
//     // 这里改为检查 right 越界的情况，见下图
//     if (right < 0 || nums[right] != target)
//         return -1;
//     return right;
// }

int main(){
    int a[] = {1, 2, 2, 2, 3, 3, 3, 4, 5, 7, 8, 9, 11, 11};
    int n; GET_ARRAY_LEN(a, n);
    int target = 11;
    int mid = binary_search(a, n, target);
    int low = lower_bound(a, n, target);
    int up = upper_bound(a, n, target);
    printf("%d %d %d\n", mid, low, up);
    
    return 0;
}