// 107. Binary Tree Level Order Traversal II.cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map <int, vector<int>> res;
    void getRes(TreeNode* root, int n){
        if(!root) return;
        getRes(root->left, n+1);
        getRes(root->right, n+1);
        res[n].push_back(root->val);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        getRes(root, 0);
        vector<vector<int>> ret;
        for(int i=res.size()-1; i>=0; i--){
            ret.push_back(res[i]);
        }
        return ret;
    }
};