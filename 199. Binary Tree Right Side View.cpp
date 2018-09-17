// 199. Binary Tree Right Side View.cpp
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
    vector<int> rightView;
    void scanTree(TreeNode* root, int depth){
        if(root!=NULL){
            if(depth>rightView.size()){
                // cout<<depth<<" "<<root->val<<" size "<<rightView.size()<<endl;
                rightView.push_back(root->val);
            }
            ++depth;
            scanTree(root->right, depth);
            scanTree(root->left, depth);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        scanTree(root, 1);
        return rightView;
    }
};