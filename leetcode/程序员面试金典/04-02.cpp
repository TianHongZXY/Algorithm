#include <cstdio>
#include <ios>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void swap(TreeNode* left, TreeNode* right){
        if(left->val < right->val) return;
        int temp = left->val;
        left->val = right->val;
        right->val = temp;
        return;
    }
    void insert(TreeNode* root, int val){
        if(root->val > val){
            if(root->left == NULL){
                root->left = new TreeNode(val);
                if(root->right != NULL)
                    swap(root->left, root->right); 
            }
            else if(root->right == NULL){
                root->right = new TreeNode(val);
                swap(root->left, root->right);
            }
            else 
                insert(root->left, val);
        }
        if(root->val < val){
            if(root->right == NULL){
                root->right = new TreeNode(val);
                if(root->left != NULL)
                    swap(root->left, root->right); 
            }
            else if(root->left == NULL){
                root->left = new TreeNode(val);
                swap(root->left, root->right);
            }
            else
                insert(root->right, val);
        }
        return;
    }
    TreeNode* sortedArrayToBST2(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        int mid_idx = nums.size() / 2;
        int mid = nums[mid_idx];        
        TreeNode *root = new TreeNode(mid);
        for(int i = mid_idx - 1, j = mid_idx + 1; i >= 0 || j < nums.size(); i--, j++){
            if(i >= 0) insert(root, nums[i]);
            if(j < nums.size()) insert(root, nums[j]);
        } 
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums){
        if(nums.size() == 0)
            return NULL;
        int mid = nums.size() / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid + 1, nums.end());
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        return root;
    }
};
