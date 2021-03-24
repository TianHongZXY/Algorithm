// Definition for a binary tree node.
#include <cstdint>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        res.push_back((long)root->val);
        dfs(root->right);
    }

    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        dfs(root);
        for(int i = 1; i < res.size(); i++)
            if(res[i] <= res[i - 1]) return false;
        return true;
    }

    bool dfs2(TreeNode* root, long min, long max){
        if(!root) return true;
        if(root->val >= max || root->val <= min) return false;
        return dfs2(root->left, min, root->val) & dfs2(root->right, root->val, max);
    }
    bool isValidBST(TreeNode* root){
        return dfs2(root, INT64_MIN, INT64_MAX);
    }
private:
    vector<long> res;
};
