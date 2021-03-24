#include <ios>
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void getOrderString(TreeNode* t, string& a) {
        if(!t) {
            a += 'X';
            return;
        }
        a += to_string(t->val);
        a += ' ';
        getOrderString(t->left, a);
        getOrderString(t->right, a);
        return;
    }

    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        string s1, s2;
        getOrderString(t1, s1);
        getOrderString(t2, s2);
        return s1.find(s2) != string::npos; 
    }
};


class Solution {
public:
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if(!t2) return true;
        return subTree(t1, t2);
    }

    bool subTree(TreeNode* t1, TreeNode* t2) {
        if(!t1) return false;
        else if(t1->val == t2->val && matchTree(t1, t2)) return true;
        return subTree(t1->left, t2) || subTree(t1->right, t2);
    }

    bool matchTree(TreeNode* t1, TreeNode* t2){
        if(!t1 && !t2) return true;
        else if(t1 && t2 && t1->val == t2->val) return matchTree(t1->left, t2->left) && matchTree(t1->right, t2->right);
        else return false;
    }
}


class Solution {
public:
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if(!t2) return true;
        if(!t1) return false;

        if(t1->val == t2->val) {
            return checkSubTree(t1->left, t2->left) && checkSubTree(t1->right, t2->right);
        }
        else{
            return checkSubTree(t1->left, t2) || checkSubTree(t1->right, t2);
        }
    }
};
