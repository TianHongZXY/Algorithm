//
// Created by TianHongZXY on 2020/4/11.
//
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (k * nums.size() == 0) return nums;
    if (k == 1) return nums;
    deque<int> dq;
    vector<int> res;
    // 初始化，将前k-1个元素加入dq，遇到队尾比要加入的元素小，则推出队尾元素，保证队列头为最大元素
    for (int i = 0; i < k-1; i++) {
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        // 将当前元素加入队列
        dq.push_back(i);
    }
    // 维护一个[left, right]的窗口，从[0, k-1]开始
    int left = 0, right = k - 1;
    while (right <= nums.size() - 1) {
        // 把队列中在left之前的元素推出
        while (!dq.empty() && dq.front() < left) {
            dq.pop_front();
        }
        // 把队尾比新元素小的推出，保证队列头为最大元素
        while (!dq.empty() && nums[dq.back()] < nums[right]) {
            dq.pop_back();
        }
        // 加入新元素
        dq.push_back(right);
        res.push_back(nums[dq.front()]);
        // 滑动窗口
        left++; right++;
    }
    return res;
    }

// 官方解法
//vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//
//    vector<int> res;
//    deque<int> deque;
//
//    for (int i = 0; i < nums.size(); i++) {
//
//        if (!deque.empty() && deque.front() == i-k)
//            deque.pop_front();
//        while (!deque.empty() && nums[i] > nums[deque.back()])
//            deque.pop_back();
//        deque.push_back(i);
//        if (i >= k-1)
//            res.push_back(nums[deque.front()]);
//    }
//
//    return res;
//}

int main(){
    int k = 5;
    vector<int> nums = {9,10,9,-7,-4,-8,2,-6};
    vector<int> res = maxSlidingWindow(nums, k);
    for(auto p: res) cout << p << " ";
}
