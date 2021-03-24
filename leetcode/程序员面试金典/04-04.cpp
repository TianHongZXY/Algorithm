// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#define max(x, y) (x > y ? x : y)
class Solution {
public:
    int dfs(TreeNode* root){
        // 后续遍历
        if(!flag) return 0;
        int lh = 0, rh = 0;
        if(root->left) lh = dfs(root->left) + 1; 
        if(root->right) rh = dfs(root->right) + 1;
        if(lh - rh > 1 || lh - rh < -1) flag = false;
        return max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
       // 计算每个树的左子树和右子树的高度
        if(root) dfs(root);
        return flag;
    }
private:
    bool flag = true;
};
