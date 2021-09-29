#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

void dfs(vector<int> nums, vector<vector<int> >& res) {
    // 边界情况单独处理
    if(nums.size() == 0) return;
    if(nums.size() == 1) { res.push_back(nums); vector<vector<int> > tmp; tmp.push_back(nums); return ; }
    if(nums.size() == 2) { 
        vector<vector<int> > tmp; tmp.push_back({nums[0]}); tmp.push_back({nums[1]}); tmp.push_back(nums); 
        res.insert(res.end(), tmp.begin(), tmp.end());
        return ; 
    }
    // subset of {a, b, c, d} = subset of {a, b, c} and plus them with d
    vector<int> lo(nums.size() - 1);
    copy(nums.begin(), nums.begin() + nums.size() - 1, lo.begin());
    vector<int> last(1, nums[nums.size() - 1]);
    dfs(lo, res);
    // plus all subset with d
    vector<vector<int> > copy_of_res(res);
    for(int i = 0; i < copy_of_res.size(); i++)
        copy_of_res[i].push_back(last[0]);
    res.insert(res.end(), copy_of_res.begin(), copy_of_res.end());
    res.push_back(last);

    return ;
}

vector<vector<int> > subsets(vector<int>& nums) {
    vector<vector<int> > res;
    vector<int> null;
    dfs(nums, res);
    // 空集要最后加，不然会出现重复的情况
    res.push_back(null);
    return res;
}

vector<vector<int> > subsets1(vector<int>& nums) {
    vector<vector<int> > res;
    res.reserve(pow(2, nums.size()));
    res.push_back(vector<int>());
    for(int n : nums) {
        int len = res.size();
        for(int i = 0; i < len; i++) {
            vector<int> subset = res[i];
            subset.push_back(n);
            res.push_back(::move(subset));
        }
    }
    return res; 
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int> > res = subsets(nums);
    for(auto v : res){
        for(auto c : v)
            cout << c << " ";
        cout << endl;
    }

    return 0;
}
