// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    if(!root) return next;
    if(root->val > p->val){
        if(next == NULL || root->val < next->val) next = root;
        inorderSuccessor(root->left, p);
    } 
    if(root->val <= p->val){
        inorderSuccessor(root->right, p);
    } 
    return next;
}

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    if(root == NULL) return NULL;
    // 中序遍历，找到第一个大于p的节点就返回
    TreeNode* res = inorderSuccessor(root->left, p);
    if(res != NULL) return res;
    if(root->val > p->val) return root;
    return inorderSuccessor(root->right, p);
}

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    /* https://leetcode-cn.com/problems/successor-lcci/solution/zhong-xu-bian-li-de-xia-yi-ge-yuan-su-5da-jie-fa-h/
     * 二叉搜索树的中序遍历是递增的
     * 如果节点p的值大于等于root的值，说明p的后继节点在root的右子树中，那么就递归到右子树查找
     * 如果节点p的值小于root的值，说明p在root的左子树中，而它的后继节点有两个可能，要么在root的左子树里，要么是root本身
     * 如果在左子树中找到了后继节点，那么返回答案，如果左子树里没找到后继节点，说明p的右子树为NULL，则root就是p的后继节点*/
    if (root == NULL || p == NULL) return NULL;
    if (p->val >= root->val) {
        return inorderSuccessor(root->right, p);
    } else {
        TreeNode* left = inorderSuccessor(root->left, p);
        return left ? left : root;
    }
}

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    if(p->right){
        TreeNode* res = p->right;
        while(res->left) res = res->left;
        return res;
    }
    else{
        TreeNode* q = root, *res;
        while(q && q != p){
            if(q->val > p ->val){
                res = q; q = q->left;
            }
            else q = q->right;
        }
        return res;
    }
}
private:
TreeNode* next = NULL;
};
