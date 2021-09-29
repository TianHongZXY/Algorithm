#include <vector>
#include <cmath>
using namespace std;

int findMagicIndex(vector<int>& nums) {
    for(int i = 0; i < nums.size();) {
        if(nums[i] == i)
            return i;
        i = max(i + 1, nums[i]);
    }
    return -1;
}
