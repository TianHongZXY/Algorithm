#include <bits/c++config.h>
#include <cstdio>
#include <utility>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include <unordered_map>
using namespace std;
class Solution {
public:

    int helper(TreeNode* root, int cur, int sum, unordered_map<int, int>& mp) {
        int res = 0;
        if(!root) return 0;
        cur += root->val;
        if(mp.count(cur - sum)) res += mp[cur - sum];
        mp[cur] += 1;
        res += helper(root->left, cur, sum, mp);
        res += helper(root->right, cur, sum, mp);
        mp[cur] -= 1;
        return res;
    }
    

    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> mp;
        mp.insert(pair<int, int>(0, 1));
        return helper(root, 0, sum, mp);
    }
};


class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        // 先计算包含根节点的情况，在递归求解不包含根节点的左右子树，统计相加即可。
        if(!root) return 0;
        // 以当前节点为路径开头的结果数，加上以左子树和右子树为路径开头的结果数
        return path(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

    int path(TreeNode* root, int target) {
        if(!root) return 0;
        int res = 0;
        if(root->val == target) res = 1;
        res += path(root->left, target - root->val);
        res += path(root->right, target - root->val);
        return res;
    }
};
