// Definition for a binary tree node.
#include <exception>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#include <vector>
#include <cstdio>
#include <queue>
using namespace std;
vector<ListNode*> res;
void create_linklist(queue<TreeNode*>& Q){
    ListNode *dummy = new ListNode(0), *p;
    p = dummy;
    queue<TreeNode*> nextQ;
    while(!Q.empty()){
       TreeNode *cur = Q.front(); Q.pop();
       p->next = new ListNode(cur->val);
       p = p->next;
       if(cur->left) nextQ.push(cur->left);
       if(cur->right) nextQ.push(cur->right);
    }
    res.push_back(dummy->next);
    delete dummy;
    if(!nextQ.empty()) create_linklist(nextQ);
    return;
}
vector<ListNode*> listOfDepth(TreeNode* tree) {
   queue<TreeNode*> Q; Q.push(tree);     
   create_linklist(Q);
   return res;
}

vector<ListNode*> listOfDepth1(TreeNode* tree) {
   queue<TreeNode*> Q; Q.push(tree);     
   vector<ListNode*> res;
   while(!Q.empty()){
       int num = Q.size();
       ListNode *dummy = new ListNode(0), *p;
       p = dummy;
       for(int i = 0; i < num; i++){
           TreeNode *cur = Q.front(); Q.pop();
           p->next = new ListNode(cur->val);
           p = p->next; 
           if(cur->left) Q.push(cur->left);
           if(cur->right) Q.push(cur->right);
       }
       res.push_back(dummy->next);
       delete dummy;
   }
   return res;
}
