struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include <vector>
#include<deque>
using namespace std;

class Solution {
public:
    vector<vector<int>> BSTSequences(TreeNode* root) {
        vector<vector<int> > results;
        if(!root){
            results.push_back(*new vector<int>());
            return results;
        }
        vector<int> prefix;
        prefix.push_back(root->val);

        vector<vector<int> > leftSeq = BSTSequences(root->left);
        vector<vector<int> > rightSeq = BSTSequences(root->right);

        for(vector<int> left: leftSeq) {
            for(vector<int> right: rightSeq) {
                // vector<vector<int> > weaved;
                weaveLists(left, right, results, prefix);
                // results.insert(results.end(), weaved.begin(), weaved.end());
            }
        }
        return results; 
    }

    void weaveLists(vector<int>& first, vector<int>& second, vector<vector<int> >& results, 
            vector<int>& prefix) {
        if(first.size() == 0 || second.size() == 0) {
            vector<int> res(prefix);
            res.insert(res.end(), first.begin(), first.end());
            res.insert(res.end(), second.begin(), second.end());
            results.push_back(res);
            return;
        }
        int headFirst = first[0]; first.erase(first.begin());
        prefix.push_back(headFirst);
        weaveLists(first, second, results, prefix);
        prefix.pop_back();
        first.insert(first.begin(), headFirst);

        int headSecond = second[0]; second.erase(second.begin());
        prefix.push_back(headSecond);
        weaveLists(first, second, results, prefix);
        prefix.pop_back();
        second.insert(second.begin(), headSecond);
        
        
    }
};


class Solution {
public:
vector<int> path;
vector<vector<int>> res;
vector<vector<int>> BSTSequences(TreeNode* root) {
    if (!root) return {{}};
    deque<TreeNode*> dq;
    dq.push_back(root);
    dfs(dq);
    return res;
}

void dfs(deque<TreeNode*>& dq) {
    // base case
    if (dq.empty()) {
        res.push_back(path);
        return;
    }

    int size = dq.size();
    for (int i = 0; i < size; i++) {
        TreeNode* node = dq.front();
        dq.pop_front();

        // 将当前值加入path
        path.push_back(node -> val);

        // 将当前节点的子节点加入选择节点
        if (node -> left) dq.push_back(node -> left);
        if (node -> right) dq.push_back(node -> right);

        // 下一轮递归
        dfs(dq);

        // 回溯选择列表
        if (node -> left) dq.pop_back();
        if (node -> right) dq.pop_back();
        // 把加入的子节点pop出后，还要将当前节点重新加入选择列表
        dq.push_back(node);

        // 回溯path
        path.pop_back();
    }
}
};


