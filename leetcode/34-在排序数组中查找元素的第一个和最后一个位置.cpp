    #include <vector>
    using namespace std;
    
    class Solution {
    public:
        int lower_bound(vector<int>& nums, int target){
            int left = 0, right = nums.size();
            while(left < right){
                int mid = left + (right - left) / 2;
                if(nums[mid] >= target){
                    right = mid;
                }
                else if(nums[mid] < target){
                    left = mid + 1;
                }
            }
            if(left == nums.size() || nums[left] != target) return -1;
            return left;
        }
        int upper_bound(vector<int>& nums, int target){
            int left = 0, right = nums.size();
            while(left < right){
                int mid = left + (right - left) / 2;
                if(nums[mid] <= target){
                    left = mid + 1;
                }
                else if(nums[mid] > target){
                    right = mid;
                }
            }
            left -= 1;
            if(left < 0 || nums[left] != target) return -1;
            return left;
        }

        vector<int> searchRange(vector<int>& nums, int target) {
            vector<int> res;
            res.push_back(lower_bound(nums, target));
            res.push_back(upper_bound(nums, target));
            return res;
        }
    };