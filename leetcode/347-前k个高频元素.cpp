//
// Created by TianHongZXY on 2020/4/12.
//
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct cmp {
    bool operator() (const pair<int, int> a, const pair<int, int> b)
    {
        return a.second > b.second; // 大的反而优先级小，即维护小根堆
    }
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> mp;
    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp > pq;
    for(int i = 0; i < nums.size(); i++){
        mp[nums[i]]++;
    }
    for(auto it: mp){
        if(pq.size() == k){
            if(it.second < pq.top().second)
                continue;
            pq.pop();
        }
        pq.push(make_pair(it.first, it.second));
    }
    vector<int> res(k);
    while(!pq.empty()){
        res[--k] = pq.top().first; pq.pop();
    }
    return res;
}

// leetcode其他用户解法，少了个cmp函数
vector<int> topKFrequent__(vector<int>& nums, int k) {
    // pair<count, val>
    // top k, min heap(小根堆)
    using E = std::pair<int, int>;
    std::priority_queue<E, std::vector<E>, std::greater<E>> minHeap;
    map<int, int> counter;

    for (auto e : nums) {
        ++counter[e];
    }

    for (auto& x : counter) {
        auto pair = make_pair(x.second, x.first);
        if (minHeap.size() == k) {
            if (pair < minHeap.top()) continue;
            minHeap.pop();
        }
        minHeap.push(std::move(pair));
    }
    std::vector<int> res(minHeap.size());
    k = res.size();
    while(!minHeap.empty()) {
        res[--k] = minHeap.top().second;
        minHeap.pop();
    }
    return res;
}