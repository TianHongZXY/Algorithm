//
// Created by TianHongZXY on 2020/4/12.
//
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

bool inorder_search(TreeNode* r, int& k, int tgt, int& res){
    if(r == NULL) return false;
    if(inorder_search(r->left, k, tgt, res)) return true;
    if(++k == tgt) {res = r->val; return true;}
    if(inorder_search(r->right, k, tgt,res)) return true;
    return false;
}

int kthSmallest(TreeNode* root, int k) {
    int i = 0;
    int res;
    inorder_search(root, i, k, res);
    return res;
}

int kthSmallest_no_recursion(TreeNode* root, int k) {
    stack<TreeNode*> stk;
    int i = 0;
    while(root || !stk.empty()){
        while(root){
            stk.push(root);
            root = root->left;
        }
        root = stk.top(); stk.pop();
        i++;
        if(i == k) return root->val;
        root = root->right;
    }
    return 0;
}
